/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimatt <marimatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 00:09:05 by marimatt          #+#    #+#             */
/*   Updated: 2023/07/27 23:56:15 by marimatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

int	is_line_light(char **splt, t_scene *scene, int n_splt)
{
	t_light	*light;

	printf("parsing line LIGHT\n");
	if (n_splt + FT_IS_BONUS != 4)
	{
		printf("error parsing file(1)\n");
		exit(1);
	}
	light = (t_light *)malloc(sizeof(t_light));
	if (light == NULL)
	{
		printf("error parsing file(2)\n");
		exit(1);
	}
	if (parse_vector_string(splt[1], &(light->position)) < 0)
	{
		printf("error parsing file(3)\n");
		exit(1);
	}
	light->ratio = ft_atof(splt[2]);
	if (parse_color_string(splt[3], \
		&(light->color.r), &(light->color.g), &(light->color.b)) < 0)
	{
		printf("error parsing file (2): colors : %f, %f, %f\n", light->color.r, light->color.g, light->color.b);
		exit(1);
	}
	if (light->ratio > 1.00000000f || light->ratio < 0.0f || \
		light->color.r < 0 || light->color.r > 255 || \
		light->color.g < 0 || light->color.g > 255 || \
		light->color.b < 0 || light->color.b > 255)
	{
		printf("Error\n parsing file (4): colors : %f, %f, %f, ratio = %f\n", light->color.r, light->color.g, light->color.b, light->ratio);
		exit(1);
	}
	light->color.a = 1.0f;
	assign_something(&(scene->lights), (void *)light, scene->n_L);
	scene->n_L += 1;
	printf("Success parsing light-->Position = %f, %f, %f; colors = %f, %f, %f; ratio = %f\n", light->position.x, light->position.y, light->position.z, light->color.r, light->color.g, light->color.b, light->ratio);
	return (1);
}
