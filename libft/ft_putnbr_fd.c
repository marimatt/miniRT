/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimatt <marimatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:23:47 by marimatt          #+#    #+#             */
/*   Updated: 2022/01/24 13:29:59 by marimatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnum(int i, int fd)
{
	int	a;

	a = i + 48 ;
	write(fd, &a, 1);
}

void	ft_putnbr_fd(int nb, int fd)
{
	if (fd < 0)
		return ;
	if (nb < 0)
	{
		write(fd, "-", 1);
		if (nb == -2147483648)
		{
			write(fd, "2147483648", 10);
			return ;
		}
		nb *= -1;
	}
	if (nb > 9)
		ft_putnbr_fd(nb / 10, fd);
	ft_putnum(nb % 10, fd);
}
