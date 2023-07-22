/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimatt <marimatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 23:38:11 by marimatt          #+#    #+#             */
/*   Updated: 2023/07/23 00:54:54 by marimatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

#include "libft/libft.h"
#include "geometry/geometry.h"
#include "scene/scene.h"
#include "miniRT.h"

// int	err_close_fd_with_ret(const char *err, int fd, int ret_val)
// {
// 	if (fd >= 0)
// 		close(fd);
// 	printf("%s", err);
// 	return (ret_val);
// }

// void	error_and_exit(char *msg)
// {
// 	printf("%s\n", msg);
// 	exit(1);
// }

int	len_of_double_ptr(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i] != NULL)
		i++;
	return (i);
}

// void	assign_something(t_list **last, void *content, int len)
// {
// 	t_list		*new_element;

// 	new_element = ft_lstnew(content);
// 	if (new_element == NULL)
// 		error_and_exit("could not malloc for a new ambient list\n");
// 	if (len == 0)
// 		*last = new_element;
// 	else
// 		ft_lstadd_back(last, new_element);
// }

int	check_line(char **splt, t_scene *scn)
{
	int	n_splt;

	n_splt = len_of_double_ptr(splt);
	if (n_splt == 1 && ft_strncmp(splt[0], "\n", 1) == 0)
		return (1);
	if (ft_strncmp(splt[0], "L", 1) == 0 && is_line_light(splt, scn, n_splt))
		return (1);
	if (ft_strncmp(splt[0], "C", 1) == 0 && is_line_camera(splt, scn, n_splt))
		return (1);
	if (ft_strncmp(splt[0], "A", 1) == 0 && is_line_ambient(splt, scn, n_splt))
		return (1);
	if (ft_strncmp(splt[0], "pl", 2) == 0 && is_line_plane(splt, scn, n_splt))
		return (1);
	if (ft_strncmp(splt[0], "sp", 2) == 0 && is_line_sphere(splt, scn, n_splt))
		return (1);
	if (ft_strncmp(splt[0], "cy", 2) == 0 && is_line_cylinder(splt, scn, n_splt))
		return (1);
	// if (ft_strncmp(splt[0], "cn", 2) == 0 && is_line_cone(splt, scn, n_splt))
	// 	return (1);
	// if (ft_strncmp(splt[0], "sq", 2) == 0 && is_line_square(splt, scn, n_splt))
	// 	return (1);
	// if (ft_strncmp(splt[0], "tr", 2) == 0 && is_line_triangle(splt, scn, n_splt))
	// 	return (1);
	printf("no matching template\n");
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
	while (v_str[i] != NULL)
	{
		printf("v_str[%d] : %s\n", i, v_str[i]);
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
	line = get_next_line(fd);
	while (line && success > 0)
	{
		splitted = ft_split(line, ' ');

		print_double_char(splitted);

		if (check_line(splitted, scene) < 0 || count_objects(scene) < 0)
			success = -1;

		free(line);
		free_splitted(&splitted);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	if (splitted)
		free_splitted(&splitted);
	printf("end of while assign_scene, success = %d\n", success);
	return (success);
}

int	main()
{
	int	fd;
	const char *file_name = "infile.rt";
	t_scene *scene;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return(err_close_fd_with_ret("Error accessing file!\n", fd, -1));

	scene = (t_scene *)malloc(sizeof(*scene));
	if (!scene)
		return (-1);

	if (assign_scene(scene, fd) < 0)
		return(err_close_fd_with_ret("Error parsing file!\n", fd, -1));
	free(scene);
	close(fd);
	return (1);
}
