/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimatt <marimatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 01:05:26 by marimatt          #+#    #+#             */
/*   Updated: 2023/07/23 23:14:46 by marimatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"

float	dot_product(t_vector *v1, t_vector *v2)
{
	return ((v1->x * v2->x) + (v1->y * v2->y) + (v1->z * v2->z));
}

float	get_squared_norm(t_vector *v)
{
	return (dot_product(v, v));
}

void	normalize_vector(t_vector *v, float norm)
{
	v->x /= norm;
	v->y /= norm;
	v->z /= norm;
	return ;
}

t_vector	cross_product(t_vector *v1, t_vector *v2)
{
	t_vector	v3;

	v3.x = v1->y * v2->z - v1->z * v2->y;
	v3.y = v1->z * v2->x - v1->x * v2->z;
	v3.z = v1->x * v2->y - v1->y * v2->z;
	return (v3);
}

t_vector	vector_composition(t_vector *v1, t_vector *v2, float c1, float c2)
{
	t_vector	v3;

	v3.x = c1 * v1->x + c2 * v2->x;
	v3.y = c1 * v1->y + c2 * v2->y;
	v3.z = c1 * v1->z + c2 * v2->z;
	return (v3);	
}

// t_vector	*cross_product(t_vector *v1, t_vector *v2)
// {
// 	t_vector	*c;

// 	c = (t_vector*)malloc(sizeof(t_vector));
// 	if (!c)
// 	{
// 		write(1, "Error on malloc for a new vector!\n", 34);
// 		exit(1);
// 	}
// 	c->x = v1->y * v2->z - v1->z * v2->y;
// 	c->y = v1->z * v2->x - v1->x * v2->z;
// 	c->z = v1->x * v2->y - v1->y * v2->z;
// 	return (c);
// }