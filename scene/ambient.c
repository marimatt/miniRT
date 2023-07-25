/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimatt <marimatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 00:07:05 by marimatt          #+#    #+#             */
/*   Updated: 2023/07/26 01:21:36 by marimatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

int	is_line_ambient(char **splt, t_scene *scene, int n_splt)
{
	printf("parsing line AMBIENT\n");
	if (n_splt != 3)
	{
		printf("Error\n parsing file (1)\n");
		exit(1);
	}
	scene->ambient.ratio = ft_atof(splt[1]);
	if (parse_color_string(splt[2], \
		&(scene->ambient.color.r), &(scene->ambient.color.g), &(scene->ambient.color.b)) < 0)
	{
		printf("Error\n parsing file (2): colors : %f, %f, %f\n", scene->ambient.color.r, scene->ambient.color.g, scene->ambient.color.b);
		exit(1);
	}
	scene->ambient.color.a = 255;
	if (scene->ambient.ratio > 1.0f || scene->ambient.ratio < 0.0f || \
		scene->ambient.color.r < 0 || scene->ambient.color.r > 255 || \
		scene->ambient.color.g < 0 || scene->ambient.color.g > 255 || \
		scene->ambient.color.b < 0 || scene->ambient.color.b > 255)
	{
		printf("Error\n parsing file (3)\n");
		exit(1);
	}
	scene->n_A += 1;
	return (1);
}
