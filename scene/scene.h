/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimatt <marimatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 00:14:10 by marimatt          #+#    #+#             */
/*   Updated: 2023/07/26 01:19:50 by marimatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
#define SCENE_H

#include "../geometry/geometry.h"
#include "../libft/libft.h"
#include <stdio.h>

#define FT_IS_BONUS 0
#define XY_RATIO 1

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

typedef struct s_screen{
	t_vector	central;
	t_vector	u;
	t_vector	v;
	float		t_u_min;
	float		t_v_min;
	float		du;
	float		dv;
}				t_screen;

typedef struct s_obj{
	void		*obj;
	int			id;
}				t_obj;

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
	t_ambient	ambient;
	int			n_A;
	t_camera	camera;
	int			n_C;
	int			tot_obj;
	t_obj		*all_obj;
	t_screen	screen;
}				t_scene;

int		is_line_ambient(char **splt, t_scene *scene, int n_splt);
int		is_line_light(char **splt, t_scene *scene, int n_splt);
int		is_line_camera(char **splt, t_scene *scene, int n_splt);

int		is_line_plane(char **splt, t_scene *scene, int n_splt);
int		is_line_sphere(char **splt, t_scene *scene, int n_splt);
int		is_line_cylinder(char **splt, t_scene *scene, int n_splt);

int		parse_color_string(char *rgb_string, float *r, float *g, float *b);
int		parse_vector_string(char *rgb_string, t_vector *vector);

void	assign_something(t_list **last, void *content, int len);

#endif
