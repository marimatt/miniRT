/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimatt <marimatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 11:15:06 by marimatt          #+#    #+#             */
/*   Updated: 2023/06/30 11:15:06 by marimatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <math.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>
# include "libft/libft.h"
# include "geometry/geometry.h"
# include "scene/scene.h"

# define FT_IS_BONUS 0
# define FT_CANVAS_WIDTH 750
# define FT_CANVAS_HEIGHT 750
# define MAX_REFLECTIONS 50
# define MAX_DIST 10000.0f
# define EYE_DIST 0.1f

# define ID_PL 1
# define ID_SP 2
# define ID_CY 3
# define ID_CN 4

# define X_MOUSE_EVENT 4
# define X_MOUSE_MASK (1L << 2)
# define X_CROSS_EVENT 17
# define X_CROSS_MASK 0
# define KEY_ESC_CODE 65307

typedef struct s_param{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				width;
	int				height;
	t_scene			scene;
}					t_param;

typedef struct s_ray{
	t_vector	origin;
	t_vector	direction;
	t_color		color;
	t_vector	pos_hit;
	t_vector	normal;
	int			hit_obj_id;
	void		*hit_obj;
	float		t;
}				t_ray;


// TO DELETE
void	print_vector(t_vector v, const char *str);


// errors
int		err_close_fd_with_ret(const char *err, int fd, int ret_val);
void	error_and_exit(char *msg);

// memory
void	free_scene(t_param *param);
void	free_splitted(char ***splitted);
int		free_with_ret(void *ptr, int ret);
void	free_list_content(void *content);

// inits
int		init_param(t_param *param);
void	init_scene(t_scene *sc);
int		set_obj_arr(t_scene *scene);
void	set_screen(t_param *param, t_screen *screen);


// main
int		my_quit(void *param);
int		hooks_keys(int key, void *param);
int		hook_mouse(int button, int x, int y, t_param *p);

// draw
void	ft_draw(t_param *param, t_screen *screen);

// parse
int		assign_scene(t_scene *scene, int fd);

//
void	ray_trace(t_param *param, t_ray *ray);
float	float_abs(float f);
float	max_float(float f1, float f2);

// intersections
void		get_next_intersection(t_param *param, t_ray *ray);
t_vector	sub_vectors(t_vector *v1, t_vector *v2);
float		intersect_plane(t_param *param, t_ray *ray, t_plane *plane);
float		intersect_sphere(t_param *param, t_ray *ray, t_sphere *sphere);
float		intersect_cylinder(t_param *param, t_ray *ray, t_cylinder *cylinder);

// colors
t_color		get_plane_color(t_param *param, t_ray *ray, t_plane *pl);
t_color		get_sphere_color(t_param *param, t_ray *ray, t_sphere *sp);
t_color		get_cylinder_color(t_param *param, t_ray *ray, t_cylinder *cy);
// t_color	get_cone_color(t_param *param, t_ray *ray, t_cone *cn);

t_vector	get_perpedincular(t_vector *v);

#endif
