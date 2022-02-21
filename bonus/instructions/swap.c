/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krulindi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 20:09:25 by krulindi          #+#    #+#             */
/*   Updated: 2022/02/21 20:09:32 by krulindi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ft_s_stack(t_stack *stack)
{
	unsigned int	value;

	if (stack)
	{
		value = stack->value;
		stack->value = (stack->down)->value;
		(stack->down)->value = value;
	}
}

void	ft_ss(t_stack **a, t_stack **b)
{
	unsigned int	value;

	if (*a)
	{
		value = (*a)->value;
		(*a)->value = ((*a)->down)->value;
		((*a)->down)->value = value;
	}
	if (*b)
	{
		value = (*b)->value;
		(*b)->value = ((*b)->down)->value;
		((*b)->down)->value = value;
	}
}
