/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimatt <marimatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 00:24:12 by marimatt          #+#    #+#             */
/*   Updated: 2023/07/22 23:45:27 by marimatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

int	err_close_fd_with_ret(const char *err, int fd, int ret_val)
{
	if (fd >= 0)
		close(fd);
	printf("%s", err);
	return (ret_val);
}

void	error_and_exit(char *msg)
{
	printf("%s\n", msg);
	exit(1);
}
