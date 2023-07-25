/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimatt <marimatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 01:40:49 by marimatt          #+#    #+#             */
/*   Updated: 2023/07/26 01:02:40 by marimatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

t_vector	sub_vectors(t_vector *v1, t_vector *v2)
{
	t_vector	v3;

	v3.x = v1->x - v2->x;
	v3.y = v1->y - v2->y;
	v3.z = v1->z - v2->z;
	return (v3);
}

float	intersect_plane(t_param *param, t_ray *ray, t_plane *plane)
{
	return (MAX_DIST);
}

float	intersect_sphere(t_param *param, t_ray *ray, t_sphere *sphere)
{
	t_vector	v_dist;
	float		half_b;
	float		c;
	float		delta;
	float		t;

	v_dist = sub_vectors(&(ray->origin), &(sphere->position));
	half_b = dot_product(&(ray->direction), &v_dist);
	c = dot_product(&v_dist, &v_dist) - (sphere->radius * sphere->radius);
	delta = half_b * half_b - c;
	if (delta < 0.00001)
		return (MAX_DIST);
	delta = sqrtf(delta);
	t = -half_b - sqrtf(delta);
	if (t < 0.00000f)
		t = -half_b + sqrtf(delta);
	if (t < 0.00000f)
		return (MAX_DIST);
	return (t);
}

float	intersect_cylinder(t_param *param, t_ray *ray, t_cylinder *cylinder)
{
	return (MAX_DIST);
}

// float	intersect_cone(t_param *param, t_ray *ray, t_cone *cone)
// {

// }
