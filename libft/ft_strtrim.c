/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimatt <marimatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 12:51:30 by marimatt          #+#    #+#             */
/*   Updated: 2022/01/21 12:51:30 by marimatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char const c, char const *set)
{
	while (*set != '\0')
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	unsigned int	len_s1;

	if (s1 == NULL || set == NULL)
		return (NULL);
	if (s1[0] == '\0')
		return ((char *)s1);
	len_s1 = 0;
	start = 0;
	while (s1[len_s1] != '\0')
		len_s1++;
	while (start < len_s1 && is_set(s1[start], set) == 1)
		start++;
	while (len_s1 > 0 && is_set(s1[len_s1 - 1], set) == 1)
		len_s1--;
	return (ft_substr(s1, start, (size_t)(len_s1 - start)));
}
