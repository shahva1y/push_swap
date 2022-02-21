/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krulindi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 20:05:55 by krulindi          #+#    #+#             */
/*   Updated: 2022/02/21 20:05:59 by krulindi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_is_sorted(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp->value != 0)
		tmp = tmp->down;
	stack = tmp;
	while (tmp->value < (tmp->down)->value)
		tmp = tmp->down;
	if ((tmp->down)->value != 0)
		return (0);
	return (1);
}
