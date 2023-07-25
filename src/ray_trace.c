/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_trace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimatt <marimatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 00:38:04 by marimatt          #+#    #+#             */
/*   Updated: 2023/07/25 02:02:40 by marimatt         ###   ########.fr       */
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
	return ;
}

void ray_trace(t_param *param, t_ray *ray)
{
	int	counter;

	counter = MAX_REFLECTIONS;
	while (counter > 0)
	{
		get_next_intersection(param, ray);
		if (float_abs(ray->t - MAX_DIST) < 0.0000f)
			break ;
		// ray->origin = ray->pos_hit;
		// ray->direction = get_new_direction(param, ray);
		// ray->pos_hit = vector_composition(&ray->origin, &ray->direction, 1.0f, ray->t);
		// // ft_bump_and_texture(ray, _, data);
		// update_ray_color(param, ray);
		counter--;
	}
	return ;
}
