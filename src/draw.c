/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimatt <marimatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 22:42:45 by marimatt          #+#    #+#             */
/*   Updated: 2023/07/25 00:53:31 by marimatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

int	create_trgb(unsigned char t, unsigned char r, \
				unsigned char g, unsigned char b)
{
	return (*(int *)(unsigned char [4]){b, g, r, t});
}

int	from_color_to_int(t_color c)
{
	return (create_trgb((int)c.a, (int)c.r, (int)c.g, (int)c.b));
}

void	my_mlx_pixel_put(t_param *p, int x, int y, int color)
{
	char	*dst;

	dst = p->addr + (y * p->line_length + x * (p->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	set_ray_direction(t_screen *screen, t_vector *direction, int i, int j)
{
	direction->x += (screen->t_u_min + i * screen->du) * screen->u.x + \
					(screen->t_v_min + j * screen->dv) * screen->v.x;
	direction->y += (screen->t_u_min + i * screen->du) * screen->u.y + \
					(screen->t_v_min + j * screen->dv) * screen->v.y;
	direction->z += (screen->t_u_min + i * screen->du) * screen->u.z + \
					(screen->t_v_min + j * screen->dv) * screen->v.z;
	normalize_vector(direction, sqrt(get_squared_norm(direction)));
	return ;
}

void	ft_draw(t_param *param, t_screen *screen)
{
	t_ray	ray;
	int		i;
	int		j;

	ray.origin = param->scene.camera.position;
	i = -1;
	while (++i < param->width)
	{
		j = -1;
		while (++j < param->height)
		{
			ray.direction.x = screen->central.x - param->scene.camera.position.x;
			ray.direction.y = screen->central.y - param->scene.camera.position.y;
			ray.direction.z = screen->central.z - param->scene.camera.position.z;
			set_ray_direction(screen, &(ray.direction), i, j);
			ray_trace(param, &ray);
			my_mlx_pixel_put(param, i, j, from_color_to_int(ray.color));
		}
	}
}
