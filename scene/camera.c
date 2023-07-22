/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimatt <marimatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 00:09:11 by marimatt          #+#    #+#             */
/*   Updated: 2023/07/23 00:48:50 by marimatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

int	is_line_camera(char **splt, t_scene *scene, int n_splt)
{
	t_camera	*camera;

	printf("parsing line CAMERA\n");
	if (n_splt != 4)
	{
		printf("error parsing file (1)\n");
		exit(1);
	}
	camera = (t_camera *)malloc(sizeof(t_camera));
	if (camera == NULL)
	{
		printf("could not malloc for a new camera\n");
		exit(1);
	}
	if (parse_vector_string(splt[1], &(camera->position)) < 0)
	{
		printf("error parsing file(2)\n");
		exit(1);
	}
	if (parse_vector_string(splt[2], &(camera->orientation)) < 0)
	{
		printf("error parsing file(3)\n");
		exit(1);
	}
	camera->fov = ft_atoi(splt[3]);
	camera->orientation.sq_norm = get_squared_norm(&(camera->orientation));
	if (camera->fov > 180.0f || camera->fov < 0.0f || \
		camera->orientation.sq_norm > 1.01f)
	{
		printf("error parsing file(4)\n");
		exit(1);
	}
	assign_something(&(scene->cameras), (void *)camera, scene->n_C);
	scene->n_C += 1;
	return (1);
}
