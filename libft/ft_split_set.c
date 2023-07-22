/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimatt <marimatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 01:00:36 by marimatt          #+#    #+#             */
/*   Updated: 2023/07/22 22:42:47 by marimatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static int	ft_char_in_set(char c, char const *set)
{
	int	i;

	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	ft_num_words(const char *str, char const *set)
{
	int	k;
	int	n;
	int	temp;

	n = 0;
	k = 0;
	if (ft_strlen(set) == 0 && ft_strlen(str) > 0)
		return (1);
	if (ft_strlen(str) == 0)
		return (0);
	while (str[k] != '\0')
	{
		while (str[k] != '\0' && ft_char_in_set(str[k], set) == 1)
			k++;
		temp = k;
		while (str[k] != '\0' && ft_char_in_set(str[k], set) == 0)
			k++;
		temp = k - temp;
		while (str[k] != '\0' && ft_char_in_set(str[k], set) == 1)
			k++;
		if (temp > 0)
			n++;
	}
	return (n);
}

static const char	*ft_find_word(const char *str, char const *set, int pos, int *len)
{
	int		k;
	int		n;

	*len = 0;
	n = 0;
	k = 0;
	while (str[k] != '\0')
	{
		while (ft_char_in_set(str[k], set))
			k++;
		while (str[k] && !ft_char_in_set(str[k], set))
		{
			if (n == pos)
				(*len)++;
			k++;
		}
		if (*len > 0)
			return (&(str[k - *len]));
		while (str[k] && ft_char_in_set(str[k], set) > 0)
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

char	**ft_split_set(char const *s, char const *set)
{
	char		**res;
	const char	*temp;
	int			num;
	int			n;
	int			len;

	num = ft_num_words(s, set);
	res = (char **)malloc(sizeof(char *) * (num + 1));
	if (res == NULL)
		return (NULL);
	n = 0;
	while (n < num)
	{
		temp = ft_find_word(s, set, n, &len);
		res[n] = (char *)malloc(sizeof(char) * (len + 1));
		if (res[n] == NULL)
			return (NULL);
		res[n] = copy_word(res[n], temp, len);
		n++;
	}
	res[n] = NULL;
	return (res);
}
