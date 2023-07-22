/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimatt <marimatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 12:37:34 by marimatt          #+#    #+#             */
/*   Updated: 2022/01/31 14:02:54 by marimatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_num_words(const char *str, char sep)
{
	int	k;
	int	n;
	int	temp;

	n = 0;
	k = 0;
	if (sep == '\0' && ft_strlen(str) > 0)
		return (1);
	if (ft_strlen(str) == 0)
		return (0);
	while (str[k] != '\0')
	{
		while (str[k] == sep)
			k++;
		temp = k;
		while (str[k] != '\0' && str[k] != sep)
			k++;
		temp = k - temp;
		while (str[k] != '\0' && str[k] == sep)
			k++;
		if (temp > 0)
			n++;
	}
	return (n);
}

static const char	*ft_find_word(const char *str, char sep, int pos, int *len)
{
	int		k;
	int		n;

	*len = 0;
	n = 0;
	k = 0;
	while (str[k] != '\0')
	{
		while (str[k] == sep)
			k++;
		while (str[k] && str[k] != sep)
		{
			if (n == pos)
				(*len)++;
			k++;
		}
		if (*len > 0)
			return (&(str[k - *len]));
		while (str[k] && str[k] == sep)
			k++;
		n++;
	}
	return (NULL);
}

static char	*copy_word(char *res, const char *src, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		res[i] = src[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char		**res;
	const char	*temp;
	int			num;
	int			n;
	int			len;

	num = ft_num_words(s, c);
	res = (char **)malloc(sizeof(char *) * (num + 1));
	if (res == NULL)
		return (NULL);
	n = 0;
	while (n < num)
	{
		temp = ft_find_word(s, c, n, &len);
		res[n] = (char *)malloc(sizeof(char) * (len + 1));
		if (res[n] == NULL)
			return (NULL);
		res[n] = copy_word(res[n], temp, len);
		n++;
	}
	res[n] = NULL;
	return (res);
}
