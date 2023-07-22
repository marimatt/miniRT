/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimatt <marimatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 23:38:11 by marimatt          #+#    #+#             */
/*   Updated: 2023/07/22 23:49:51 by marimatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

int	len_of_double_ptr(void **ptr)
{
	int	i;

	i = 0;
	while (ptr[i] != NULL)
		i++;
	return (i);
}

int	check_line(char **splt, t_scene *scene)
{
	int	n_splt;

	n_splt = len_of_double_ptr(splt);
	if (n_splt == 1 && ft_strncmp(splt[0], "\n", 1) == 0)
		return (1);
	if (ft_strncmp(splt[0], "L", 1) == 0 && is_line_light(splt, scene, n_splt))
		return (1);
	if (ft_strncmp(splt[0], "C", 1) == 0 && is_line_camera(splt, scene, n_splt))
		return (1);
	if (ft_strncmp(splt[0], "A", 1) == 0 && is_line_ambient(splt, scene, n_splt))
		return (1);
	if (ft_strncmp(splt[0], "sp", 2) == 0 && is_line_sphere(splt, scene, n_splt))
		return (1);
	if (ft_strncmp(splt[0], "pl", 2) == 0 && is_line_plane(splt, scene, n_splt))
		return (1);
	if (ft_strncmp(splt[0], "cy", 2) == 0 && is_line_cylinder(splt, scene, n_splt))
		return (1);
	if (ft_strncmp(splt[0], "cn", 2) == 0 && is_line_cone(splt, scene, n_splt))
		return (1);
	// if (ft_strncmp(splt[0], "sq", 2) == 0 && is_line_square(splt, scene, n_splt))
	// 	return (1);
	// if (ft_strncmp(splt[0], "tr", 2) == 0 && is_line_triangle(splt, scene, n_splt))
	// 	return (1);
	return (-1);
}

int	count_objects(t_scene *scene)
{
	if (scene->n_A > 1 || scene->n_C > 1)
		return (-1);
	if (!FT_IS_BONUS)
	{
		if (scene->n_L > 1 || scene->n_cn)// || scene->n_tr || scene->n_sq)
			return (-1);
	}
	return (1);
}

void	print_double_char(char **v_str)
{
	int	i;

	i = 0;
	while (v_str[i])
	{
		printf("v_str[%d] : %s.\n", i, v_str[i]);
		i++;
	}
	return ;
}

int	assign_scene(t_scene *scene, int fd)
{
	int		success;
	char	*line;
	char	**splitted;

	success = 1;
	line = NULL;
	splitted = NULL;
	while (get_next_line(&line, fd) == 1 && success)
	{
		splitted = ft_split_set(line, "\t\f\r\v ,");

		print_double_char(splitted);

		if (check_line(splitted, scene) < 0 || count_objects(scene) < 0)
			success = -1;

		free(line);
		free_splitted(&splitted);
	}
	if (line)
		free(line);
	if (splitted)
		free_splitted(&splitted);
	return (success);
}
