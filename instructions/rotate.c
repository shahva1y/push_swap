/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krulindi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 20:07:54 by krulindi          #+#    #+#             */
/*   Updated: 2022/02/21 20:07:58 by krulindi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rotate(t_stack **stack, char stack_name)
{
	if (*stack)
	{
		(*stack) = (*stack)->down;
		write(1, "r", 1);
		write(1, &stack_name, 1);
		write(1, "\n", 1);
	}
}

void	ft_reverse_rotate(t_stack **stack, char stack_name)
{
	if (*stack)
	{
		(*stack) = (*stack)->up;
		write(1, "rr", 2);
		write(1, &stack_name, 1);
		write(1, "\n", 1);
	}
}

void	ft_both_rotate(t_stack **a, t_stack **b)
{
	if (*a)
		(*a) = (*a)->down;
	if (*b)
		(*b) = (*b)->down;
	if (*a || *b)
		write(1, "rr\n", 3);
}

void	ft_both_reverse_rotate(t_stack **a, t_stack **b)
{
	if (*a)
		(*a) = (*a)->up;
	if (*b)
		(*b) = (*b)->up;
	if (*a || *b)
		write(1, "rrr\n", 4);
}
