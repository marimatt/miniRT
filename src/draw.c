/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimatt <marimatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 22:42:45 by marimatt          #+#    #+#             */
/*   Updated: 2023/07/24 01:20:43 by marimatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

int	create_trgb(unsigned char t, unsigned char r, \
				unsigned char g, unsigned char b)
{
	return (*(int *)(unsigned char [4]){b, g, r, t});
}

void	my_mlx_pixel_put(t_param *p, int x, int y, int color)
{
	char	*dst;

	dst = p->addr + (y * p->line_length + x * (p->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	get_pixel_color(t_param *param, t_vector *ray)
{
	(void)param;
	(void)ray;
	return (create_trgb(255, 255, 255, 255));	
}

void	ft_draw(t_param *param, t_screen *screen)
{
	t_vector	ray;
	int			i;
	int			j;

	i = -1;
	while (++i < param->width)
	{
		j = -1;
		while (++j < param->height)
		{
			ray.x =	(screen->central.x - param->scene.camera.position.x) + \
							(screen->t_u_min + i * screen->du) * screen->u.x + \
							(screen->t_v_min + j * screen->dv) * screen->v.x;
			ray.y =	(screen->central.y - param->scene.camera.position.y) + \
							(screen->t_u_min + i * screen->du) * screen->u.y + \
							(screen->t_v_min + j * screen->dv) * screen->v.y;
			ray.z =	(screen->central.z - param->scene.camera.position.z) + \
							(screen->t_u_min + i * screen->du) * screen->u.z + \
							(screen->t_v_min + j * screen->dv) * screen->v.z;
			normalize_vector(&ray, sqrt(get_squared_norm(&ray)));
			my_mlx_pixel_put(param, i, j, get_pixel_color(param, &ray));
		}
	}
}
