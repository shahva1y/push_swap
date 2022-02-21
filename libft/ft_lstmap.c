/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krulindi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:14:18 by krulindi          #+#    #+#             */
/*   Updated: 2021/10/17 16:26:20 by krulindi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*curnt;
	t_list	*new;
	t_list	*newlst;

	newlst = (void *)0;
	while (lst != (void *)0)
	{
		curnt = lst;
		lst = lst->next;
		new = ft_lstnew((*f)(curnt->content));
		if (new == (void *)0)
		{
			ft_lstclear(&newlst, del);
			return ((void *)0);
		}
		ft_lstadd_back(&newlst, new);
	}	
	return (newlst);
}
