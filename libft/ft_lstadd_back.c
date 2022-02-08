/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krulindi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 13:23:43 by krulindi          #+#    #+#             */
/*   Updated: 2021/10/16 15:49:27 by krulindi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*elem;

	elem = *lst;
	if (elem != (void *)0 && new != (void *)0)
	{
		while (elem->next != (void *)0)
			elem = elem->next;
		elem->next = new;
	}
	else if (new != (void *)0)
		(*lst) = new;
}
