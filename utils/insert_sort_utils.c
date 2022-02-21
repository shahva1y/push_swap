/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_sort_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krulindi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 20:06:08 by krulindi          #+#    #+#             */
/*   Updated: 2022/02/21 20:06:11 by krulindi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_is_rotate_dst(t_stack *element, t_stack *dst)
{
	int	result;

	result = ((element->value > dst->value)
			&& (dst->index == element->index));
	return (result);
}

int	ft_is_rrotate_dst(t_stack *element, t_stack *dst)
{
	int	result;

	result = ((element->value < dst->value)
			&& (element->value < (dst->up)->value)
			&& ((dst->up)->index == element->index)
			&& (dst->index == element->index));
	return (result);
}

unsigned long long	ft_rotate_count_to_insert(t_stack *element, t_stack *stack)
{
	unsigned long long	count;

	count = 0;
	while (element->value > stack->value && stack->index == element->index)
	{
		count++;
		stack = stack->down;
	}
	while (element->value < stack->value
		&& (stack->up)->index == element->index
		&& stack->index == element->index)
	{
		count++;
		stack = stack->up;
	}
	return (count);
}

void	ft_change_elements_index(t_stack *stack)
{
	t_stack		*tmp;
	long long	index;

	tmp = stack;
	index = stack->index;
	while (tmp != tmp->up && (tmp->up)->index == index)
		tmp = tmp->up;
	while (tmp->index == index)
	{
		tmp->index = -1;
		tmp = tmp->down;
	}
}
