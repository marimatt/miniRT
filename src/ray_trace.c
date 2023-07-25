/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_trace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimatt <marimatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 00:38:04 by marimatt          #+#    #+#             */
/*   Updated: 2023/07/26 01:18:52 by marimatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void	get_next_intersection(t_param *param, t_ray *ray)
{
	float	t;
	int		i;

	ray->t = MAX_DIST;
	i = -1;
	while (++i < param->scene.tot_obj)
	{
		if (param->scene.all_obj[i].id == ID_PL)
			t = intersect_plane(param, ray, param->scene.all_obj[i].obj);
		else if (param->scene.all_obj[i].id == ID_SP)
			t = intersect_sphere(param, ray, param->scene.all_obj[i].obj);
		else if (param->scene.all_obj[i].id == ID_CY)
			t = intersect_cylinder(param, ray, param->scene.all_obj[i].obj);
		else if (param->scene.all_obj[i].id == ID_CN && FT_IS_BONUS)
			t = intersect_cone(param, ray, param->scene.all_obj[i].obj);
		if (t < 0)
			continue ;
		if (t < ray->t)
		{
			ray->hit_obj = param->scene.all_obj[i].obj;
			ray->hit_obj_id = param->scene.all_obj[i].id;
			ray->t = t;
		}
	}
}

t_vector	get_new_direction(t_param *param, t_ray *ray)
{
	return (ray->direction);
}

void	update_ray_color(t_param *param, t_ray *ray)
{
	t_color	color;

	if (ray->hit_obj_id == ID_PL)
		color = get_plane_color(param, ray, ray->hit_obj);
	else if (ray->hit_obj_id == ID_SP)
		color = get_sphere_color(param, ray, ray->hit_obj);
	else if (ray->hit_obj_id == ID_CY)
		color = get_cylinder_color(param, ray, ray->hit_obj);
	// else if (ray->hit_obj_id == ID_CN)
	// 	color = get_cone_color(param, ray, ray->hit_obj);

	ray->color.r += color.r;
	ray->color.g += color.g;
	ray->color.b += color.b;
}

void ray_trace(t_param *param, t_ray *ray)
{
	int	counter;

	counter = MAX_REFLECTIONS;
	while (counter > 0)
	{
		get_next_intersection(param, ray);
		if (ray->hit_obj_id < 0 || ray->t >= MAX_DIST)
			break ;
		ray->pos_hit = vector_composition(&ray->origin, &ray->direction, 1.0f, ray->t);
		// printf("ray hit a %i at t %f in %f,%f,%f\n", ray->hit_obj_id, ray->t, ray->pos_hit.x, ray->pos_hit.y, ray->pos_hit.z);
		// // ft_bump_and_texture(ray, _, data);
		update_ray_color(param, ray);
		// ray->origin = ray->pos_hit;
		// ray->direction = get_new_direction(param, ray);
		counter--;
	}
	return ;
}
