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
# define FT_CANVAS_WIDTH 500
# define FT_CANVAS_HEIGHT 500

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

// errors
int		err_close_fd_with_ret(const char *err, int fd, int ret_val);
void	error_and_exit(char *msg);

// memory
void	free_scene(t_param *param);
void	free_splitted(char ***splitted);
int		free_with_ret(void *ptr, int ret);
void	free_list_content(void *content);

// inits
int		init_all(t_param *param, const char *file_name);

// main
int		my_quit(void *param);
int		hooks_keys(int key, void *param);
int		hook_mouse(int button, int x, int y, t_param *p);

// draw
void	ft_draw(t_param *param, t_screen *screen);

// parse
int		assign_scene(t_scene *scene, int fd);

#endif
