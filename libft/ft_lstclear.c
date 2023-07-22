/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimatt <marimatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 12:39:51 by marimatt          #+#    #+#             */
/*   Updated: 2022/01/21 12:39:51 by marimatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*dopo;

	dopo = *lst;
	while (dopo)
	{
		tmp = dopo->next;
		ft_lstdelone(dopo, del);
		dopo = tmp;
	}
	*lst = NULL;
}
