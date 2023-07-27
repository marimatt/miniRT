/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimatt <marimatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 22:44:55 by marimatt          #+#    #+#             */
/*   Updated: 2023/07/26 23:20:06 by marimatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"
#include <stdio.h>

void	assign_something(t_list **last, void *content, int len)
{
	t_list		*new_element;

	new_element = ft_lstnew(content);
	if (new_element == NULL)
	{
		printf("could not malloc for a new ambient list\n");
		exit(1);
	}
	if (len == 0)
		*last = new_element;
	else
		ft_lstadd_back(last, new_element);
}

int	parse_color_string(char *rgb_string, float *r, float *g, float *b)
{
	char	**splitted;
	int		i;

	splitted = ft_split(rgb_string, ',');
	if (!splitted)
	{
		printf("could not malloc for splitted color!\n");
		exit(1);
	}
	i = 0;
	while (splitted[i] && i < 3)
	{
		if (i == 0)
			*r = ft_atof(splitted[i]) / 255.0f;
		else if (i == 1)
			*g = ft_atof(splitted[i]) / 255.0f;
		else if (i == 2)
			*b = ft_atof(splitted[i]) / 255.0f;
		free(splitted[i]);
		i++;
	}
	free(splitted);
	if (i != 3)
		return (-1);
	return (1);
}

int	parse_vector_string(char *rgb_string, t_vector *vector)
{
	char	**splitted;
	int		i;

	splitted = ft_split(rgb_string, ',');
	if (!splitted)
	{
		printf("could not malloc for splitted color!\n");
		exit(1);
	}
	i = 0;
	while (splitted[i] && i < 3)
	{
		if (i == 0)
			vector->x = ft_atof(splitted[i]);
		else if (i == 1)
			vector->y = ft_atof(splitted[i]);
		else if (i == 2)
			vector->z = ft_atof(splitted[i]);
		free(splitted[i]);
		i++;
	}
	free(splitted);
	if (i != 3)
		return (-1);
	return (1);
}
