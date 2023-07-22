/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimatt <marimatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 12:45:22 by marimatt          #+#    #+#             */
/*   Updated: 2023/07/22 19:43:34 by marimatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_and_null(char **str, int is_free)
{
	if (is_free > 0 && str != NULL && *str != NULL)
	{
		free(*str);
		*str = NULL;
	}
}

char	*ft_substr_2(char *s, int start, int len, int is_free)
{
	int		i;
	char	*sub;

	if (!s || start >= ft_strlen_2(s))
	{
		free_and_null(&s, is_free);
		return (NULL);
	}
	sub = malloc(sizeof(*sub) * (len + 1));
	if (sub == NULL)
	{
		free_and_null(&s, is_free);
		return (NULL);
	}
	i = 0;
	while (s[i + start] != '\0' && i < len)
	{
		sub[i] = s[i + start];
		i++;
	}
	sub[i] = '\0';
	free_and_null(&s, is_free);
	return (sub);
}

int	is_new_line(char *s)
{
	int	n;

	if (!s)
		return (-1);
	n = 0;
	while (s[n] != '\0')
	{
		if (s[n] == '\n')
			return (n);
		n++;
	}
	return (-1);
}

char	*init_buffer(void)
{
	char	*buff;
	int		n;

	buff = (char *)malloc(sizeof(*buff) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	n = 0;
	while (n < BUFFER_SIZE + 1)
	{
		buff[n] = '\0';
		n++;
	}
	return (buff);
}

int	ft_strlen_2(char *s)
{
	int	l;

	if (!s)
		return (-1);
	l = 0;
	while (s[l] != '\0')
		l++;
	return (l);
}
