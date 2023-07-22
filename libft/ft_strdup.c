/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimatt <marimatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 12:46:30 by marimatt          #+#    #+#             */
/*   Updated: 2022/01/21 12:46:30 by marimatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		len;
	char	*cpy;

	len = 0;
	while (s[len] != '\0')
		len++;
	cpy = (char *)malloc((len + 1) * sizeof(char));
	if (cpy == NULL)
		return (NULL);
	while (len >= 0)
	{
		cpy[len] = ((char *)s)[len];
		len--;
	}
	return (cpy);
}
