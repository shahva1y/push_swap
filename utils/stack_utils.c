/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krulindi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 20:06:44 by krulindi          #+#    #+#             */
/*   Updated: 2022/02/21 20:06:48 by krulindi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_stack	*ft_create_element(unsigned int value)
{
	t_stack	*element;

	element = (t_stack *)malloc(sizeof(t_stack));
	if (!element)
		ft_error("Memory allocation error!\n");
	element->index = 0;
	element->value = value;
	return (element);
}

static void	ft_add_element_to_stack(t_stack **stack, t_stack *element)
{
	if ((*stack))
	{
		element->up = (*stack)->up;
		((*stack)->up)->down = element;
		element->down = (*stack);
		(*stack)->up = element;
	}
	else
	{
		(*stack) = element;
		element->up = (*stack);
		element->down = (*stack);
	}
}

t_stack	*create_stack(unsigned int *array, unsigned int length)
{
	unsigned int	i;
	t_stack			*stack;
	t_stack			*element;

	i = 0;
	stack = NULL;
	while (i < length)
	{
		element = ft_create_element(array[i]);
		ft_add_element_to_stack(&stack, element);
		i++;
	}
	free(array);
	return (stack);
}

unsigned long long	ft_get_stack_length(t_stack *stack)
{
	unsigned long long	length;
	t_stack				*tmp;

	tmp = stack;
	length = 0;
	if (!stack)
		return (length);
	if (tmp != tmp->down)
		tmp = tmp->down;
	length++;
	while (tmp != stack)
	{
		tmp = tmp->down;
		length++;
	}
	return (length);
}
