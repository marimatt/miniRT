/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimatt <marimatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 22:39:51 by marimatt          #+#    #+#             */
/*   Updated: 2023/07/24 01:20:24 by marimatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void	init_scene(t_scene *sc)
{
	sc->ambients = NULL;
	sc->lights = NULL;
	sc->spheres = NULL;
	sc->planes = NULL;
	sc->cylinders = NULL;
	sc->cones = NULL;
	// sc->squares = NULL;
	// sc->triangles = NULL;
	sc->n_pl = 0;
	sc->n_sp = 0;
	sc->n_cy = 0;
	// sc->n_sq = 0;
	// sc->n_tr = 0;
	sc->n_L = 0;
	sc->n_C = 0;
	sc->n_A = 0;
	sc->n_cn = 0;
}

int	init_param(t_param *param)
{
	param->mlx_ptr = NULL;
	param->win_ptr = NULL;
	param->img = NULL;
	param->addr = NULL;
	param->bits_per_pixel = 0;
	param->line_length = 0;
	param->endian = 0;
	param->width = FT_CANVAS_WIDTH;
	param->height = FT_CANVAS_HEIGHT;
	return (1);
}

float	float_abs(float f)
{
	if (f >= 0.00000000f)
		return (f);
	return(-f);	
}

void	set_screen(t_param *param, t_screen *screen)
{
	screen->u.x = - param->scene.camera.orientation.y;
	screen->u.y = + param->scene.camera.orientation.x;
	screen->u.z = 0.0f;
	screen->v = cross_product(&(screen->u), &param->scene.camera.orientation);
	normalize_vector(&(screen->u), sqrt(get_squared_norm(&(screen->u))));
	normalize_vector(&(screen->v), sqrt(get_squared_norm(&(screen->v))));
	screen->central.x = param->scene.camera.position.x + param->scene.camera.orientation.x;
	screen->central.y = param->scene.camera.position.y + param->scene.camera.orientation.y;
	screen->central.z = param->scene.camera.position.z + param->scene.camera.orientation.z;
	screen->t_u_min = - tanf(0.5f * param->scene.camera.fov * 3.14159f / 180.0f);
	screen->t_v_min = screen->t_u_min * XY_RATIO;
	screen->du = 2 * float_abs(screen->t_u_min) / (float)FT_CANVAS_WIDTH;
	screen->dv = 2 * float_abs(screen->t_v_min) / (float)FT_CANVAS_HEIGHT;
}

int	init_all(t_param *param, const char *file_name)
{
	t_screen	screen;
	int			fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return(err_close_fd_with_ret("Error accessing file!\n", fd, -1));

	if (init_param(param) < 0)
		return(err_close_fd_with_ret("Could not init scene!\n", fd, -1));

	init_scene(&(param->scene));

	if (assign_scene(&param->scene, fd) < 0)
		return(err_close_fd_with_ret("Error parsing file!\n", fd, -1));

	set_screen(param, &screen);
	param->scene.screen = screen;
	close(fd);
	return (1);
}
