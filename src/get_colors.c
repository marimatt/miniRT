/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimatt <marimatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 01:15:09 by marimatt          #+#    #+#             */
/*   Updated: 2023/07/28 15:43:34 by marimatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

float	max_float(float f1, float f2)
{
	if (f1 < f2)
		return (f2);
	return (f1);
}

t_color check_lights(t_param *param, t_vector *pos_hit, t_vector *normal)
{
	t_list	*ptr;
	t_light	*light;
	t_ray	ray;
	float	dist;
	float	i_dot_n;

	ray.color.r = 0.00000000f;
	ray.color.g = 0.00000000f;
	ray.color.b = 0.00000000f;
	ptr = param->scene.lights;
	while (ptr != NULL)
	{
		light = (t_light *)ptr->content;
		ptr = ptr->next;
		ray.hit_obj_id = -1;
		ray.origin = *pos_hit;
		ray.direction = sub_vectors((&light->position), pos_hit);
		dist = sqrt(dot_product(&(ray.direction), &(ray.direction)));
		normalize_vector(&(ray.direction), dist);
		get_next_intersection(param, &ray);
		if (ray.hit_obj_id > 0 && ray.t < dist)
			continue ;
		i_dot_n = max_float(dot_product(&(ray.direction), normal), 0.00000000f);
		ray.color.r += light->color.r * light->ratio * i_dot_n / sqrt(dist);
		ray.color.g += light->color.g * light->ratio * i_dot_n / sqrt(dist);
		ray.color.b += light->color.b * light->ratio * i_dot_n / sqrt(dist);
	}
	return (ray.color);
}

t_color	get_plane_color(t_param *param, t_ray *ray, t_plane *pl)
{
	t_color	color;

	return (color);
}

t_color	get_sphere_color(t_param *param, t_ray *ray, t_sphere *sp)
{
	t_vector	normal;
	t_color		color_ambient;
	t_color		color_shading;

	color_ambient.r = param->scene.ambient.color.r * param->scene.ambient.ratio;
	color_ambient.g = param->scene.ambient.color.g * param->scene.ambient.ratio;
	color_ambient.b = param->scene.ambient.color.b * param->scene.ambient.ratio;

	normal = sub_vectors(&(ray->pos_hit), &(sp->position));
	normalize_vector(&normal, sqrt(get_squared_norm(&normal)));

	ray->normal = normal;

	color_shading = check_lights(param, &(ray->pos_hit), &normal);

	color_ambient.r = sp->color.r * (sp->ma * color_ambient.r + sp->ml * color_shading.r);
	color_ambient.g = sp->color.g * (sp->ma * color_ambient.g + sp->ml * color_shading.g);
	color_ambient.b = sp->color.b * (sp->ma * color_ambient.b + sp->ml * color_shading.b);

	return (color_ambient);
}

t_color	get_cylinder_color(t_param *param, t_ray *ray, t_cylinder *cy)
{
	t_color	color;

	return (color);
}

// t_color	get_cone_color(t_param *param, t_ray *ray, t_cone *cn)
// {
// 	t_color	color;

// 	return (color);
// }
