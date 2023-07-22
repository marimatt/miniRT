/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimatt <marimatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 12:53:58 by marimatt          #+#    #+#             */
/*   Updated: 2022/01/25 14:33:18 by marimatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*sub;

	if (s == NULL)
		return (NULL);
	sub = malloc(sizeof(*sub) * (len + 1));
	if (sub == NULL)
		return (sub);
	i = 0;
	if (start < (unsigned int)ft_strlen(s))
	{
		while (i < (unsigned int)len)
		{
			sub[i] = s[i + start];
			if (s[i + start] == '\0')
				break ;
			i++;
		}
	}
	sub[i] = '\0';
	return (sub);
}
