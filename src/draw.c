/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimatt <marimatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 22:42:45 by marimatt          #+#    #+#             */
/*   Updated: 2023/07/02 00:15:54 by marimatt         ###   ########.fr       */
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

void	ft_draw(t_param *param)
{
	int	i;
	int	j;
	int	color;

	i = 0;
	while (i < param->width)
	{
		j = 0;
		while (j < param->height)
		{
			color = create_trgb(i % 256, j % 256, 0, 0);
			my_mlx_pixel_put(param, i, j, color);
			j++;
		}
		i++;
	}
}
