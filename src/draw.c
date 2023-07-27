/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimatt <marimatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 22:42:45 by marimatt          #+#    #+#             */
/*   Updated: 2023/07/28 01:23:47 by marimatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

int	create_trgb(unsigned char t, unsigned char r, \
				unsigned char g, unsigned char b)
{
	return (*(int *)(unsigned char [4]){b, g, r, t});
}

int	from_color_to_int(t_color *c)
{
	float	m;
	float	s;

	s = c->r + c->g + c->b;
	// c->r /= s;
	// c->g /= s;
	// c->b /= s;
	m = 1.0f; //max_float(c->r, max_float(c->g, c->b));
	// if (m > 1.0f)
	// 	m = 1.0f;
	return (create_trgb((int)255 * c->a, (int)255 * c->r / m, (int)255 * c->g / m, (int)255 * c->b / m));
}

void	my_mlx_pixel_put(t_param *p, int x, int y, int color)
{
	char	*dst;

	dst = p->addr + (y * p->line_length + x * (p->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	reset_ray(t_screen *screen, t_ray *ray, int i, int j)
{
	ray->direction.x += (screen->t_u_min + i * screen->du) * screen->u.x + \
						(screen->t_v_min + j * screen->dv) * screen->v.x;
	ray->direction.y += (screen->t_u_min + i * screen->du) * screen->u.y + \
						(screen->t_v_min + j * screen->dv) * screen->v.y;
	ray->direction.z += (screen->t_u_min + i * screen->du) * screen->u.z + \
						(screen->t_v_min + j * screen->dv) * screen->v.z;
	normalize_vector(&(ray->direction), sqrt(get_squared_norm(&(ray->direction))));
	ray->color.r = 0.00000000f;
	ray->color.g = 0.00000000f;
	ray->color.b = 0.00000000f;
	ray->hit_obj = NULL;
	ray->hit_obj_id = -1;
	return ;
}

void	ft_draw(t_param *param, t_screen *screen)
{
	t_ray	ray;
	int		i;
	int		j;

	i = -1;
	while (++i < param->width)
	{
		j = -1;
		while (++j < param->height)
		{
			ray.origin = param->scene.camera.position;
			ray.direction.x = screen->central.x - param->scene.camera.position.x;
			ray.direction.y = screen->central.y - param->scene.camera.position.y;
			ray.direction.z = screen->central.z - param->scene.camera.position.z;
			reset_ray(screen, &ray, i, j);
			ray_trace(param, &ray);
			my_mlx_pixel_put(param, i, j, from_color_to_int(&(ray.color)));
		}
	}
}
