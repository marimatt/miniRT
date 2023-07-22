/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimatt <marimatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 12:47:14 by marimatt          #+#    #+#             */
/*   Updated: 2022/01/21 12:47:14 by marimatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*k;
	int		l1;
	int		l2;

	if (!s1 || !s2)
		return (NULL);
	l1 = (int)ft_strlen(s1);
	l2 = (int)ft_strlen(s2);
	k = (char *)malloc(sizeof(*k) *(l1 + l2 + 1));
	if (k == NULL)
		return (NULL);
	while (l2-- >= 0)
		k[l1 + l2 + 1] = s2[l2 + 1];
	while (l1-- > 0)
		k[l1] = s1[l1];
	return (k);
}
