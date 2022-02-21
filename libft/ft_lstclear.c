/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krulindi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 13:29:33 by krulindi          #+#    #+#             */
/*   Updated: 2021/10/16 13:49:04 by krulindi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*curnt;

	while (*lst != (void *)0 && del != (void *)0)
	{
		curnt = *lst;
		(*lst) = (*lst)->next;
		(*del)(curnt->content);
		free(curnt);
	}
}
