/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimatt <marimatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 01:15:09 by marimatt          #+#    #+#             */
/*   Updated: 2023/07/26 01:37:29 by marimatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

t_color	get_plane_color(t_param *param, t_ray *ray, t_plane *pl)
{
	t_color	color;

	return (color);
}

t_color	get_sphere_color(t_param *param, t_ray *ray, t_sphere *sp)
{
	t_color	color;

	color.r = (sp->color.r / 255) * param->scene.ambient.color.r * param->scene.ambient.ratio;
	color.g = (sp->color.g / 255) * param->scene.ambient.color.g * param->scene.ambient.ratio;
	color.b = (sp->color.b / 255) * param->scene.ambient.color.b * param->scene.ambient.ratio;
	return (color);
}

t_color	get_cylinder_color(t_param *param, t_ray *ray, t_cylinder *cy)
{
	t_color	color;

	return (color);
}

// t_color	get_cone_color(t_param *param, t_ray *ray, t_cone *cn)
// {
// 	t_color	color;

// 	return (color);
// }