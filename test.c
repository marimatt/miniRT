/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimatt <marimatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 23:38:11 by marimatt          #+#    #+#             */
/*   Updated: 2023/07/26 00:28:54 by marimatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int main()
{

	printf("%f ", ft_atof("2.0005"));
}

// int	main()
// {
// 	int	fd;
// 	const char *file_name = "infile.rt";
// 	t_scene *scene;

// 	fd = open(file_name, O_RDONLY);
// 	if (fd == -1)
// 		return(err_close_fd_with_ret("Error accessing file!\n", fd, -1));

// 	scene = (t_scene *)malloc(sizeof(*scene));
// 	if (!scene)
// 		return (-1);

// 	if (assign_scene(scene, fd) < 0)
// 		return(err_close_fd_with_ret("Error parsing file!\n", fd, -1));
// 	free(scene);
// 	close(fd);
// 	return (1);
// }
