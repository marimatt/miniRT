/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimatt <marimatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 12:25:54 by marimatt          #+#    #+#             */
/*   Updated: 2022/01/21 12:25:54 by marimatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;
	size_t	n;

	n = 0;
	ptr = (char *)malloc(nmemb * size);
	if (ptr == NULL)
		return (ptr);
	while (n < nmemb * size)
	{
		ptr[n] = '\0';
		n++;
	}
	return ((void *) ptr);
}
