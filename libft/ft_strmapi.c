/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimatt <marimatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 12:49:46 by marimatt          #+#    #+#             */
/*   Updated: 2022/01/21 12:49:46 by marimatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*fs;
	size_t	len;

	if (!s || !f)
		return (0);
	len = ft_strlen(s);
	fs = (char *)malloc(sizeof(*fs) * (len + 1));
	if (fs == NULL)
		return (NULL);
	fs[len] = '\0';
	while (len > 0)
	{
		len--;
		fs[len] = (*f)((unsigned int)len, (char)s[len]);
	}
	return (fs);
}
