/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krulindi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 20:10:11 by krulindi          #+#    #+#             */
/*   Updated: 2022/02/21 20:10:15 by krulindi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_simple_sort(t_stack **stack)
{
	if (((((*stack)->up)->value < ((*stack)->down)->value)
			&& ((*stack)->value < ((*stack)->up)->value))
		|| (((*stack)->value > ((*stack)->down)->value)
			&& (((*stack)->up)->value <= ((*stack)->down)->value))
		|| ((((*stack)->up)->value > (*stack)->value)
			&& ((*stack)->value > ((*stack)->down)->value)))
		ft_swap(*stack, 'a');
	if (((*stack)->value > ((*stack)->up)->value)
		&& (((*stack)->up)->value >= ((*stack)->down)->value))
		ft_rotate(stack, 'a');
	if (((*stack)->value < ((*stack)->down)->value)
		&& (*stack)->value > ((*stack)->up)->value)
		ft_reverse_rotate(stack, 'a');
}
