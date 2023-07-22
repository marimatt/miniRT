/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimatt <marimatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 10:52:11 by marimatt          #+#    #+#             */
/*   Updated: 2023/07/23 01:31:12 by marimatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

int	my_quit(void *param)
{
	t_param	*p;

	p = (t_param *)param;
	mlx_destroy_window(p->mlx_ptr, p->win_ptr);
	free_scene(p);
	exit (0);
	return (0);
}

// int	create_trgb(unsigned char t, unsigned char r, unsigned char g, unsigned char b)
// {
// 	return (*(int *)(unsigned char [4]){b, g, r, t});
// }

int main(int argc, char **argv)
{
	t_param	param;

	if (argc != 2 || argv[1] == NULL)
		return (1);

	if (init_all(&param, argv[1]) < 0)
		return (1);

	printf("after init_all\n");
	param.mlx_ptr = mlx_init();
	printf("after mlx_init\n");
	param.win_ptr = mlx_new_window(param.mlx_ptr, param.width, param.height, "MiniRT");
	printf("after mlx_new_window\n");

	param.img = mlx_new_image(param.mlx_ptr, param.width, param.height);
	printf("after mlx_new_image\n");

	param.addr = mlx_get_data_addr(param.img, &param.bits_per_pixel, \
									&param.line_length, &param.endian);
	printf("after mlx_get_data_addr\n");

	ft_draw(&param);
	printf("after ft_draw\n");

	mlx_key_hook(param.win_ptr, hooks_keys, (void *)&param);
	mlx_hook(param.win_ptr, X_MOUSE_EVENT, X_MOUSE_MASK, hook_mouse, &param);
	mlx_hook(param.win_ptr, X_CROSS_EVENT, X_CROSS_MASK, my_quit, (void *)&param);
	printf("after hooks\n");

	mlx_put_image_to_window(param.mlx_ptr, param.win_ptr, param.img, 0, 0);
	printf("after mlx_put_image_to_window\n");
	mlx_loop(param.mlx_ptr);
	printf("after mlx_loop\n");
	free_scene(&param);
}
