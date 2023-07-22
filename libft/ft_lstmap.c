/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimatt <marimatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 12:41:28 by marimatt          #+#    #+#             */
/*   Updated: 2022/01/21 12:41:28 by marimatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*tmp;

	if (lst == NULL)
		return (NULL);
	new = ft_lstnew((*f)((void *)(lst->content)));
	while (lst->next != NULL)
	{
		tmp = ft_lstnew((*f)((void *)(lst->content)));
		if (tmp == NULL)
			ft_lstclear(&tmp, (*del));
		else
			ft_lstadd_back(&new, tmp);
		lst = lst->next;
	}
	return (new);
}
