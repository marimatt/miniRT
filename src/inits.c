/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimatt <marimatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 22:39:51 by marimatt          #+#    #+#             */
/*   Updated: 2023/07/28 00:30:49 by marimatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void	init_scene(t_scene *sc)
{
	sc->lights = NULL;
	sc->spheres = NULL;
	sc->planes = NULL;
	sc->cylinders = NULL;
	sc->cones = NULL;
	sc->all_obj = NULL;
	sc->n_pl = 0;
	sc->n_sp = 0;
	sc->n_cy = 0;
	sc->n_L = 0;
	sc->n_C = 0;
	sc->n_A = 0;
	sc->n_cn = 0;
	sc->tot_obj = 0;
}

int	init_param(t_param *param)
{
	param->mlx_ptr = NULL;
	param->win_ptr = NULL;
	param->img = NULL;
	param->addr = NULL;
	param->bits_per_pixel = 0;
	param->line_length = 0;
	param->endian = 0;
	param->width = FT_CANVAS_WIDTH;
	param->height = FT_CANVAS_HEIGHT;
	return (1);
}

void	set_screen(t_param *param, t_screen *screen)
{
	screen->u.x = + param->scene.camera.orientation.y;
	screen->u.y = - param->scene.camera.orientation.x;
	screen->u.z = 0.0f;
	screen->v = cross_product(&(screen->u), &(param->scene.camera.orientation));

	normalize_vector(&(screen->u), sqrt(get_squared_norm(&(screen->u))));
	normalize_vector(&(screen->v), sqrt(get_squared_norm(&(screen->v))));

	screen->central.x = param->scene.camera.position.x + EYE_DIST * param->scene.camera.orientation.x;
	screen->central.y = param->scene.camera.position.y + EYE_DIST * param->scene.camera.orientation.y;
	screen->central.z = param->scene.camera.position.z + EYE_DIST * param->scene.camera.orientation.z;

	screen->t_u_min = - EYE_DIST * tanf(0.5f * param->scene.camera.fov * 3.14159f / 180.0f);
	screen->t_v_min = screen->t_u_min * XY_RATIO;
	screen->du = 2 * float_abs(screen->t_u_min) / (float)FT_CANVAS_WIDTH;
	screen->dv = 2 * float_abs(screen->t_v_min) / (float)FT_CANVAS_HEIGHT;

	print_vector(param->scene.camera.orientation, "camera");
	print_vector(screen->u, "screen->u");
	print_vector(screen->v, "screen->v");
	printf("screen->du = %f\n", screen->du);
	printf("screen->dv = %f\n", screen->dv);
	printf("screen->t_u_min = %f\n", screen->t_u_min);
	printf("screen->t_v_min = %f\n", screen->t_v_min);
}

int	add_to_all_objects(t_scene *scene, t_list *ptr, int id, int idx)
{
	while (ptr && idx++ > -2)
	{
		scene->all_obj[idx].obj = ptr->content;
		scene->all_obj[idx].id = id;
		ptr = (void *)(ptr->next);
	}
	return (idx);
}

int	set_obj_arr(t_scene *scene)
{
	int		tot_num;
	int		idx;

	tot_num = scene->n_cy + scene->n_pl + scene->n_sp + FT_IS_BONUS * scene->n_cn;
	scene->all_obj = (t_obj*)malloc(sizeof(t_obj) * tot_num);
	if (!scene->all_obj)
		return (-1);
	scene->tot_obj = tot_num;
	idx = -1;
	idx = add_to_all_objects(scene, scene->planes, ID_PL, idx);
	idx = add_to_all_objects(scene, scene->spheres, ID_SP, idx);
	idx = add_to_all_objects(scene, scene->cylinders, ID_CY, idx);
	if (FT_IS_BONUS)
		idx = add_to_all_objects(scene, scene->cylinders, ID_CN, idx);
	return (1);
}
