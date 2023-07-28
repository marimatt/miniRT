/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimatt <marimatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 01:05:25 by marimatt          #+#    #+#             */
/*   Updated: 2023/07/28 14:16:56 by marimatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GEOMETRY_H
# define GEOMETRY_H

#include <math.h>

typedef struct s_vector{
	float	x;
	float	y;
	float	z;
	float	sq_norm;
}				t_vector;

typedef struct s_color{
	float	r;
	float	g;
	float	b;
	float	a;
}				t_color;

typedef struct s_plane{
	t_vector	position;
	t_vector	orientation;
	t_color		color;
	float		ma;
	float		ml;
	float		ms;
	float		met;
}				t_plane;

typedef struct s_cylinder{
	t_vector	position;
	t_vector	orientation;
	float		diameter;
	float		height;
	float		ma;
	float		ml;
	float		ms;
	float		met;
	t_color		color;
}				t_cylinder;

typedef struct s_sphere{
	t_vector	position;
	float		radius;
	float		ma;
	float		ml;
	float		ms;
	float		met;
	t_color		color;
}				t_sphere;

typedef struct s_cone{
	t_vector	orientation;
	t_vector	position;
	t_vector	u;
	t_vector	v;
	float		angle;
	float		ma;
	float		ml;
	float		ms;
	float		met;
	t_color		color;
}				t_cone;

float		get_squared_norm(t_vector *v);
void		normalize_vector(t_vector *v, float norm);
float		dot_product(t_vector *v1, t_vector *v2);
t_vector	cross_product(t_vector *v1, t_vector *v2);
t_vector	vector_composition(t_vector *v1, t_vector *v2, float c1, float c2);

#endif
