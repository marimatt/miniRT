/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimatt <marimatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 22:39:51 by marimatt          #+#    #+#             */
/*   Updated: 2023/07/22 22:28:45 by marimatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void	init_scene(t_scene *sc)
{
	sc->ambients = NULL;
	sc->cameras = NULL;
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
	t_scene	*scene;

	scene = (t_scene *)malloc(sizeof(*scene));
	if (!scene)
		return (-1);
	init_scene(scene);
	param->scene = scene;
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

int	init_all(t_param *param, const char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return(err_close_fd_with_ret("Error accessing file!\n", fd, -1));

	if (init_param(param) < 0)
		return(err_close_fd_with_ret("Could not init scene!\n", fd, -1));

	if (assign_scene(param->scene, fd) < 0)
		return(err_close_fd_with_ret("Error parsing file!\n", fd, -1));

	close(fd);
	return (1);
}
