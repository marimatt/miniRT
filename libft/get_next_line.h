/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimatt <marimatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 12:06:17 by marimatt          #+#    #+#             */
/*   Updated: 2023/07/22 19:43:48 by marimatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);

void	free_and_null(char **str, int is_free);
int		is_new_line(char *s);
char	*ft_substr_2(char *s, int start, int len, int is_free);
int		ft_strlen_2(char *s);
char	*init_buffer(void);

#endif
