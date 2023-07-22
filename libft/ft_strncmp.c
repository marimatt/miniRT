/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimatt <marimatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:26:22 by marimatt          #+#    #+#             */
/*   Updated: 2022/01/21 12:50:48 by marimatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	res;

	res = 0;
	if (n == 0)
		return (0);
	while (s1[res] == s2[res] && res < n - 1)
	{
		if (s1[res] == '\0')
			return (0);
		res++;
	}
	res = (unsigned char)s1[res] - (unsigned char)s2[res];
	res = (int) res;
	return (res);
}
