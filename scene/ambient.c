/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimatt <marimatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 00:07:05 by marimatt          #+#    #+#             */
/*   Updated: 2023/07/25 00:33:21 by marimatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

int	is_line_ambient(char **splt, t_scene *scene, int n_splt)
{
	t_ambient	*ambient;

	printf("parsing line AMBIENT\n");
	if (n_splt != 3)
	{
		printf("error parsing file (1)\n");
		exit(1);
	}
	ambient = (t_ambient *)malloc(sizeof(t_ambient));
	if (ambient == NULL)
	{
		printf("could not malloc for a new ambient\n");
		exit(1);
	}
	ambient->ratio = ft_atof(splt[1]);
	if (parse_color_string(splt[2], \
		&(ambient->color.r), &(ambient->color.g), &(ambient->color.b)) < 0)
	{
		printf("error parsing file (2): colors : %f, %f, %f\n", ambient->color.r, ambient->color.g, ambient->color.b);
		exit(1);
	}
	ambient->color.a = 255;
	if (ambient->ratio > 1.0f || ambient->ratio < 0.0f || \
		ambient->color.r < 0 || ambient->color.r > 255 || \
		ambient->color.g < 0 || ambient->color.g > 255 || \
		ambient->color.b < 0 || ambient->color.b > 255)
	{
		printf("error parsing file (3)\n");
		exit(1);
	}
	assign_something(&(scene->ambients), (void *)ambient, scene->n_A);
	scene->n_A += 1;
	return (1);
}
