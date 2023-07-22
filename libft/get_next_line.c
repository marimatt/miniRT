/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimatt <marimatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 12:45:20 by marimatt          #+#    #+#             */
/*   Updated: 2023/07/22 19:43:30 by marimatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	add_buffer(char **str, char *buff, int l2)
{
	char	*j;
	int		i;
	int		l1;

	l1 = ft_strlen_2(*str);
	if ((*str) == NULL)
		l1 = 0;
	j = (char *)malloc(sizeof(*j) * (l1 + l2 + 1));
	if (j == NULL)
	{
		free_and_null(str, 1);
		return ;
	}
	i = 0;
	while (i < l1 + l2)
	{
		if (i < l1)
			j[i] = (*str)[i];
		else
			j[i] = buff[i - l1];
		i++;
	}
	j[i] = '\0';
	free_and_null(str, 1);
	*str = j;
}

static char	*do_read_cycle(int fd, char **mem, char *buff)
{
	char	*line;
	int		n;
	int		m;

	line = ft_substr_2(*mem, 0, ft_strlen_2(*mem), 0);
	n = (int)read(fd, buff, BUFFER_SIZE);
	while (n > 0)
	{
		add_buffer(&line, buff, n);
		m = is_new_line(line);
		if (m >= 0)
		{
			free(*mem);
			*mem = ft_substr_2(line, m + 1, ft_strlen_2(line) - m - 1, 0);
			return (ft_substr_2(line, 0, m + 1, 1));
		}
		n = (int)read(fd, buff, BUFFER_SIZE);
	}
	free_and_null(mem, 1);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*mem = NULL;
	char		*line;
	char		*buff;
	int			pos;

	if (fd < 0)
		return (NULL);
	pos = is_new_line(mem);
	if (pos >= 0)
	{
		line = ft_substr_2(mem, 0, pos + 1, 0);
		mem = ft_substr_2(mem, pos + 1, ft_strlen_2(mem) - pos - 1, 1);
		return (line);
	}
	buff = init_buffer();
	if (buff == NULL)
	{
		free_and_null(&mem, 1);
		return (NULL);
	}
	line = do_read_cycle(fd, &mem, buff);
	free(buff);
	return (line);
}
