/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_geometry.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimatt <marimatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 00:24:46 by marimatt          #+#    #+#             */
/*   Updated: 2023/07/23 00:54:10 by marimatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

int	is_line_plane(char **splt, t_scene *scene, int n_splt)
{
	t_plane	*plane;

	printf("parsing line plane\n");
	if (n_splt != 4)
	{
		printf("error parsing file (1)\n");
		exit(1);
	}
	plane = (t_plane *)malloc(sizeof(t_plane));
	if (plane == NULL)
	{
		printf("could not malloc for a new plane\n");
		exit(1);
	}
	if (parse_vector_string(splt[1], &(plane->position)) < 0)
	{
		printf("error parsing file(2)\n");
		exit(1);
	}
	if (parse_vector_string(splt[2], &(plane->orientation)) < 0)
	{
		printf("error parsing file(3)\n");
		exit(1);
	}
	if (parse_color_string(splt[3], \
		&(plane->color.r), &(plane->color.g), &(plane->color.b)) < 0)
	{
		printf("error parsing file (2): colors : %d, %d, %d\n", plane->color.r, plane->color.g, plane->color.b);
		exit(1);
	}
	plane->orientation.sq_norm = get_squared_norm(&(plane->orientation));
	if (plane->orientation.sq_norm > 1.0f || \
		plane->color.r < 0 || plane->color.r > 255 || \
		plane->color.g < 0 || plane->color.g > 255 || \
		plane->color.b < 0 || plane->color.b > 255)
	{
		printf("error parsing file(4)\n");
		exit(1);
	}
	assign_something(&(scene->planes), (void *)plane, scene->n_pl);
	scene->n_pl += 1;
	return (1);
}


int	is_line_sphere(char **splt, t_scene *scene, int n_splt)
{
	t_sphere	*sphere;

	printf("parsing line sphere\n");
	if (n_splt != 4)
	{
		printf("error parsing file (1)\n");
		exit(1);
	}
	sphere = (t_sphere *)malloc(sizeof(t_sphere));
	if (sphere == NULL)
	{
		printf("could not malloc for a new sphere\n");
		exit(1);
	}
	if (parse_vector_string(splt[1], &(sphere->position)) < 0)
	{
		printf("error parsing file(2)\n");
		exit(1);
	}
	sphere->diameter = ft_atof(splt[2]);
	if (parse_color_string(splt[3], \
		&(sphere->color.r), &(sphere->color.g), &(sphere->color.b)) < 0)
	{
		printf("error parsing file (2): colors : %d, %d, %d\n", sphere->color.r, sphere->color.g, sphere->color.b);
		exit(1);
	}
	if (sphere->diameter <= 0.0f || \
		sphere->color.r < 0 || sphere->color.r > 255 || \
		sphere->color.g < 0 || sphere->color.g > 255 || \
		sphere->color.b < 0 || sphere->color.b > 255)
	{
		printf("error parsing file(4)\n");
		exit(1);
	}
	assign_something(&(scene->spheres), (void *)sphere, scene->n_sp);
	scene->n_sp += 1;
	return (1);
}


int	is_line_cylinder(char **splt, t_scene *scene, int n_splt)
{
	t_cylinder	*cylinder;

	printf("parsing line cylinder\n");
	if (n_splt != 6)
	{
		printf("error parsing file (1)\n");
		exit(1);
	}
	cylinder = (t_cylinder *)malloc(sizeof(t_cylinder));
	if (cylinder == NULL)
	{
		printf("could not malloc for a new cylinder\n");
		exit(1);
	}
	if (parse_vector_string(splt[1], &(cylinder->position)) < 0)
	{
		printf("error parsing file(2)\n");
		exit(1);
	}
	if (parse_vector_string(splt[2], &(cylinder->orientation)) < 0)
	{
		printf("error parsing file(3)\n");
		exit(1);
	}
	cylinder->diameter = ft_atof(splt[3]);
	cylinder->height = ft_atof(splt[4]);
	if (parse_color_string(splt[5], \
		&(cylinder->color.r), &(cylinder->color.g), &(cylinder->color.b)) < 0)
	{
		printf("error parsing file (2): colors : %d, %d, %d\n", cylinder->color.r, cylinder->color.g, cylinder->color.b);
		exit(1);
	}

	cylinder->orientation.sq_norm = get_squared_norm(&(cylinder->orientation));

	if (cylinder->orientation.sq_norm > 1.0f || \
		cylinder->diameter <= 0.0f || cylinder->height <= 0.0f || \
		cylinder->color.r < 0 || cylinder->color.r > 255 || \
		cylinder->color.g < 0 || cylinder->color.g > 255 || \
		cylinder->color.b < 0 || cylinder->color.b > 255)
	{
		printf("error parsing file(4)\n");
		exit(1);
	}
	assign_something(&(scene->cylinders), (void *)cylinder, scene->n_cy);
	scene->n_cy += 1;
	return (1);
}
