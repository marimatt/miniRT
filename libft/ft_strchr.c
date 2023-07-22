/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:08:31 by marimatt          #+#    #+#             */
/*   Updated: 2022/01/13 13:24:46 by marimatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char	k;
	int		i;
	char	*res;

	res = (char *)s;
	i = 0;
	k = (char)c;
	while (s[i] != '\0')
	{
		if (s[i] == k)
			return (&res[i]);
		i++;
	}
	if (s[i] == k)
		return (&res[i]);
	return (0);
}
