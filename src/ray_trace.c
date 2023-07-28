/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_trace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimatt <marimatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 00:38:04 by marimatt          #+#    #+#             */
/*   Updated: 2023/07/28 15:31:31 by marimatt         ###   ########.fr       */
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

void	update_ray_color(t_param *param, t_ray *ray, int counter)
{
	t_color		color;
	float		reflect;

	if (ray->hit_obj_id == ID_PL)
		color = get_plane_color(param, ray, ray->hit_obj);
	else if (ray->hit_obj_id == ID_SP)
		color = get_sphere_color(param, ray, ray->hit_obj);
	else if (ray->hit_obj_id == ID_CY)
		color = get_cylinder_color(param, ray, ray->hit_obj);
	// else if (ray->hit_obj_id == ID_CN)
	// 	color = get_cone_color(param, ray, ray->hit_obj);

	if (counter > 0)
	{
		reflect = 0.5f * exp(-counter / 2);
		ray->color.r = (ray->color.r * (1.0f - reflect) + color.r * reflect);
		ray->color.g = (ray->color.g * (1.0f - reflect) + color.g * reflect);
		ray->color.b = (ray->color.b * (1.0f - reflect) + color.b * reflect);
	}
	else
		ray->color = color;
}

void	vector_scalar_mult(t_vector *v, float scalar)
{
	v->x *= scalar;
	v->y *= scalar;
	v->z *= scalar;
}

void	add_infinity_color(t_ray *ray, int counter)
{
	float	reflect;

	reflect = 0.5f * exp(-counter / 2);
	ray->color.r = (ray->color.r * (1.0f - reflect) + 0.0f);
	ray->color.g = (ray->color.g * (1.0f - reflect) + 0.0f);
	ray->color.b = (ray->color.b * (1.0f - reflect) + 0.0f);
}

void ray_trace(t_param *param, t_ray *ray)
{
	int		counter;
	float	factor;

	counter = 0;
	while (counter < MAX_REFLECTIONS)
	{
		get_next_intersection(param, ray);

		if (ray->hit_obj_id < 0 || ray->t >= MAX_DIST)
		{
			add_infinity_color(ray, counter);
			break ;
		}

		ray->pos_hit = vector_composition(&ray->origin, &ray->direction, 1.0f, 0.9999 *ray->t);

		update_ray_color(param, ray, counter);
		// printf("ray hit a %i at t %f in %f,%f,%f\n", ray->hit_obj_id, ray->t, ray->pos_hit.x, ray->pos_hit.y, ray->pos_hit.z);

		factor = 2.0f * dot_product(&(ray->normal), &(ray->direction));

		vector_scalar_mult(&(ray->normal), factor);

		ray->direction = sub_vectors(&(ray->direction), &(ray->normal));

		normalize_vector(&(ray->direction), sqrt(dot_product(&(ray->direction), &(ray->direction))));

		ray->origin = ray->pos_hit;
		ray->hit_obj = NULL;
		ray->hit_obj_id = -1;

		counter++;
		// printf("counter = %d\n", counter);
	}
	return ;
}
