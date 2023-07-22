/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimatt <marimatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:14:52 by marimatt          #+#    #+#             */
/*   Updated: 2022/01/21 12:50:53 by marimatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	len_n;
	size_t	len_h;

	len_n = 0;
	len_h = 0;
	while (haystack[len_h] != '\0')
		len_h++;
	while (needle[len_n] != '\0')
		len_n++;
	if (len_n == 0)
		return ((char *)haystack);
	i = 0;
	while (haystack[i] != '\0' && i < len)
	{
		j = 0;
		while (needle[j] == haystack[i + j] && j < len_n && i + j < len)
			j++;
		if (j == len_n)
			return (&((char *)haystack)[i]);
		i++;
	}
	return (0);
}
