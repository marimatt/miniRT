/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimatt <marimatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 00:14:10 by marimatt          #+#    #+#             */
/*   Updated: 2023/07/23 01:10:18 by marimatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
#define SCENE_H

#include "../geometry/geometry.h"
#include "../libft/libft.h"
#include <stdio.h>

#define FT_IS_BONUS 0

typedef struct s_ambient{
	float	ratio;
	t_color	color;
}				t_ambient;

typedef struct s_camera{
	t_vector	position;
	t_vector	orientation;
	float		fov;
}				t_camera;

typedef struct s_light{
	t_vector	position;
	float		ratio;
	t_color		color;
}				t_light;

typedef struct s_scene{
	t_list		*planes;
	int			n_pl;
	t_list		*spheres;
	int			n_sp;
	t_list		*cylinders;
	int			n_cy;
	t_list		*cones;
	int			n_cn;
	// t_list		*squares;
	// int			n_sq;
	// t_list		*triangles;
	// int			n_tr;
	t_list		*lights;
	int			n_L;
	t_list		*cameras;
	int			n_C;
	t_list		*ambients;
	int			n_A;
}				t_scene;

int		is_line_ambient(char **splt, t_scene *scene, int n_splt);
int		is_line_light(char **splt, t_scene *scene, int n_splt);
int		is_line_camera(char **splt, t_scene *scene, int n_splt);

int		is_line_plane(char **splt, t_scene *scene, int n_splt);
int		is_line_sphere(char **splt, t_scene *scene, int n_splt);
int		is_line_cylinder(char **splt, t_scene *scene, int n_splt);

int		parse_color_string(char *rgb_string, int *r, int *g, int *b);
int		parse_vector_string(char *rgb_string, t_vector *vector);

void	assign_something(t_list **last, void *content, int len);

#endif
