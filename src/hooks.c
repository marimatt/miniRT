/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimatt <marimatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 18:10:22 by marimatt          #+#    #+#             */
/*   Updated: 2023/07/02 00:15:54 by marimatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

void	deal_space_key(t_param *p)
{
	printf("%p", p);
}

int	hook_mouse(int button, int x, int y, t_param *p)
{
	printf("%d", button);
	if ((button == 1 || button == 4)) // && p->dx > 0.00001)
	{
		printf("%d", x);
		// p->dx = p->dx / 1.5;
		// p->dy = p->dy / 1.5;
	}
	else if ((button == 2 || button == 5))// && p->dx < 10)
	{
		printf("%d", y);
		// p->dx = p->dx * 1.5;
		// p->dy = p->dy * 1.5;
	}
	if (button == 1 || button == 2 || button == 4 || button == 5)
	{
		ft_draw(p);
		mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->img, 0, 0);
	}
	return (0);
}

int	hooks_keys(int key, void *param)
{
	t_param	*p;

	p = (t_param *)param;

	printf("key pressed code : %d", key);

	if (key == KEY_ESC_CODE || key == 17)
		my_quit((void *)p);
	if (key == 49)
		deal_space_key(p);
	// if (key == 124)
	// 	// p->x += 0.2 * p->dx;
	// else if (key == 123)
	// 	// p->x -= 0.2 * p->dx;
	// else if (key == 126)
	// 	// p->y -= 0.2 * p->dy;
	// else if (key == 125)
		// p->y += 0.2 * p->dy;
	if (key == 124 || key == 125 || key == 126 || key == 123 || key == 49)
	{
		ft_draw(p);
		mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->img, 0, 0);
	}
	return (0);
}
