/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimatt <marimatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:32:28 by marimatt          #+#    #+#             */
/*   Updated: 2022/01/25 14:36:16 by marimatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	putnbr(int nb, char *s, int *count)
{
	if (nb > 9)
		putnbr(nb / 10, s, count);
	s[*count] = nb % 10 + 48;
	(*count)++;
}

static int	norm_num(int numero, int *count, char *s)
{
	if (numero < 0)
	{
		s[0] = '-';
		if (numero == -2147483648)
		{
			s[1] = '2';
			*count = 2;
			return (147483648);
		}
		*count = 1;
		return (-numero);
	}
	else
		*count = 0;
	return (numero);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		count;

	s = (char *)malloc(sizeof(*s) * 12);
	if (!s)
		return (NULL);
	putnbr(norm_num(n, &count, s), s, &count);
	while (count <= 12)
	{
		s[count] = '\0';
		count++;
	}
	return (s);
}
