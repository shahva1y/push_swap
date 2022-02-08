/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krulindi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 13:30:50 by krulindi          #+#    #+#             */
/*   Updated: 2021/10/15 13:34:45 by krulindi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*curnt;

	while (lst != (void *)0 && f != (void *)0)
	{
		curnt = lst;
		lst = lst->next;
		(*f)(curnt->content);
	}
}
