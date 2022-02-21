/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krulindi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 20:09:17 by krulindi          #+#    #+#             */
/*   Updated: 2022/02/21 20:09:21 by krulindi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ft_r_stack(t_stack **stack)
{
	if (*stack)
		(*stack) = (*stack)->down;
}

void	ft_rr_stack(t_stack **stack)
{
	if (*stack)
		(*stack) = (*stack)->up;
}

void	ft_rr(t_stack **a, t_stack **b)
{
	if (*a)
		(*a) = (*a)->down;
	if (*b)
		(*b) = (*b)->down;
}

void	ft_rrr(t_stack **a, t_stack **b)
{
	if (*a)
		(*a) = (*a)->up;
	if (*b)
		(*b) = (*b)->up;
}
