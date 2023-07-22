/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimatt <marimatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 00:30:21 by marimatt          #+#    #+#             */
/*   Updated: 2023/07/22 23:54:38 by marimatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void	free_list_content(void *content)
{
	if (content != NULL)
		free(content);
}

void	free_scene(t_param *param)
{
	ft_lstclear(&(param->scene->lights), free_list_content);
	ft_lstclear(&(param->scene->cameras), free_list_content);
	ft_lstclear(&(param->scene->ambients), free_list_content);
	ft_lstclear(&(param->scene->spheres), free_list_content);
	ft_lstclear(&(param->scene->planes), free_list_content);
	ft_lstclear(&(param->scene->cylinders), free_list_content);
	ft_lstclear(&(param->scene->cones), free_list_content);
	// ft_lstclear(param->scene->squares, free_list_content);
	// ft_lstclear(param->scene->triangles, free_list_content);
	free(param->scene);
}

void	free_splitted(char ***splitted)
{
	int	i;

	i = 0;
	while ((*splitted)[i] != NULL)
	{
		free((*splitted)[i]);
		++i;
	}
	free(*splitted);
	*splitted = NULL;
}

int	free_with_ret(void *ptr, int ret)
{
	if (ptr != NULL)
		free(ptr);
	return (ret);
}
