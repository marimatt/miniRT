/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimatt <marimatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 10:52:11 by marimatt          #+#    #+#             */
/*   Updated: 2023/07/28 14:04:37 by marimatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

float	float_abs(float f)
{
	if (f >= 0.00000000f)
		return (f);
	return(-f);	
}

int	my_quit(void *param)
{
	t_param	*p;

	p = (t_param *)param;
	mlx_destroy_window(p->mlx_ptr, p->win_ptr);
	// free_scene(p);
	exit (0);
	return (0);
}

int	init_all(t_param *param, const char *file_name)
{
	t_screen	screen;
	int			fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return(err_close_fd_with_ret("Error accessing file!\n", fd, -1));

	if (init_param(param) < 0)
		return(err_close_fd_with_ret("Could not init scene!\n", fd, -1));

	init_scene(&(param->scene));

	if (assign_scene(&param->scene, fd) < 0 || set_obj_arr(&param->scene) < 0)
		return(err_close_fd_with_ret("Error parsing file!\n", fd, -1));

	set_screen(param, &screen);
	param->scene.screen = screen;
	close(fd);
	return (1);
}

void	print_vector(t_vector v, const char *str)
{
	printf("%s = %f, %f, %f\n", str, v.x, v.y, v.z);
}

t_vector	get_perpedincular(t_vector *v)
{
	t_vector	perp;

    if (float_abs(v->z) < float_abs(v->x))
	{
		perp.x = v->y;
		perp.y = -v->x;
		perp.z = 0.0f;
	}
	else
	{
		perp.x = 0.0f;
		perp.y = -v->z;
		perp.z = v->y;
	}
	return (perp);
}

int main(int argc, char **argv)
{
	t_param	param;

	if (argc != 2 || argv[1] == NULL)
		return (1);

	if (init_all(&param, argv[1]) < 0)
		exit(1);

	int i = 0;
	while (i < param.scene.tot_obj)
	{
		printf("i:%d, id = %d\n", i, param.scene.all_obj[i].id);
		i++;
	}

	t_list *ptr;
	ptr = param.scene.lights;
	t_light *light;
	while (ptr != NULL)
	{
		light = ptr->content;
		printf("light : %f, %f, %f, ratio = %f\n", light->color.r, light->color.g, light->color.b, light->ratio);
		ptr = ptr->next;
	}

	ptr = param.scene.spheres;
	t_sphere *sp;
	while (ptr != NULL)
	{
		sp = ptr->content;
		printf("sp : %f, %f, %f, radius = %f\n", sp->position.x, sp->position.y, sp->position.z, sp->radius);
		ptr = ptr->next;
	}

	printf("before MLX_INIT\n");
	param.mlx_ptr = mlx_init();
	param.win_ptr = mlx_new_window(param.mlx_ptr, param.width, param.height, "MiniRT");
	param.img = mlx_new_image(param.mlx_ptr, param.width, param.height);
	param.addr = mlx_get_data_addr(param.img, &param.bits_per_pixel, \
									&param.line_length, &param.endian);
	printf("before ft_draw\n");
	ft_draw(&param, &(param.scene.screen));
	printf("after ft_draw\n");

	mlx_key_hook(param.win_ptr, hooks_keys, (void *)&param);
	mlx_hook(param.win_ptr, X_MOUSE_EVENT, X_MOUSE_MASK, hook_mouse, &param);
	mlx_hook(param.win_ptr, X_CROSS_EVENT, X_CROSS_MASK, my_quit, (void *)&param);
	printf("after hooks\n");

	mlx_put_image_to_window(param.mlx_ptr, param.win_ptr, param.img, 0, 0);
	printf("after mlx_put_image_to_window\n");

	mlx_loop(param.mlx_ptr);
	printf("after mlx_loop\n");

	// free_scene(&param);
}
