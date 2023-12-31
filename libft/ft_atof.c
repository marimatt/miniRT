/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimatt <marimatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 00:21:28 by marimatt          #+#    #+#             */
/*   Updated: 2023/07/28 00:15:40 by marimatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace_not_nl(char c)
{
	if (c == ' ' || c == '\f' || c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

static int	ft_to_power(int base, int pwr)
{
	int	res;

	if (pwr == 0)
		return (1);
	res = ft_to_power(base, pwr - 1) * base;
	return (res);
}

static int	ft_atoi_not_nl_no_sign(char **s_ptr, int *sign)
{
	int		res;

	res = 0;
	while (ft_isspace_not_nl(**s_ptr))
		(*s_ptr)++;
	if (**s_ptr == '+' || **s_ptr == '-')
	{
		if (**s_ptr == '-')
			*sign = -1;
		(*s_ptr)++;
	}
	while (**s_ptr >= '0' && **s_ptr <= '9')
	{
		res *= 10;
		res += **s_ptr - '0';
		(*s_ptr)++;
	}
	return (res);
}

float	ft_atof(char *str)
{
	float	number;
	int		counter;
	int		sign;

	sign = 1;
	number = (float)ft_atoi_not_nl_no_sign(&str, &sign);
	if (*str == '.')
	{
		str++;
		counter = 1;
		while (*str >= '0' && *str <= '9')
		{
			number += (float)(*str - '0') / ft_to_power(10, counter);
			str++;
			counter++;
		}
	}
	if (sign > 0)
		return (number);
	return (-number);
}
