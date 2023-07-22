/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimatt <marimatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 01:05:25 by marimatt          #+#    #+#             */
/*   Updated: 2023/07/23 01:10:22 by marimatt         ###   ########.fr       */
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
	int	r;
	int	g;
	int	b;
	int a;
}				t_color;

typedef struct s_plane{
	t_vector	position;
	t_vector	orientation;
	t_color		color;
}				t_plane;

typedef struct s_cylinder{
	t_vector	position;
	t_vector	orientation;
	float		diameter;
	float		height;
	t_color		color;
}				t_cylinder;

typedef struct s_sphere{
	t_vector	position;
	float		diameter;
	t_color		color;
}				t_sphere;

float	get_squared_norm(t_vector *v);

#endif
