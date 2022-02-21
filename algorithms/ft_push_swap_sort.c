/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krulindi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 20:10:01 by krulindi          #+#    #+#             */
/*   Updated: 2022/02/21 20:10:05 by krulindi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_increase_index(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	if (!stack)
		return ;
	(tmp->index)++;
	tmp = tmp->down;
	while (tmp != stack)
	{
		(tmp->index)++;
		tmp = tmp->down;
	}
}

/*
 * Изменить название функции ft_rotate_to_next_pack
*/
static void	ft_rotate_to_next_pack(t_stack **stack)
{
	t_stack	*tmp;

	tmp = (*stack);
	if (tmp->index == -1 && tmp != tmp->down)
		tmp = tmp->down;
	while (tmp->index == -1 && tmp != (*stack))
		tmp = tmp->down;
	while ((*stack) != tmp)
		ft_rotate(stack, 'a');
}

void	ft_status_update(t_stack **stack, t_status *status)
{
	t_stack				*tmp;

	if (!(*stack))
		return ;
	tmp = (*stack);
	status->max = (*stack)->value;
	status->min = (*stack)->value;
	if ((*stack)->index == -1)
		return ;
	if (tmp != tmp->down)
		tmp = tmp->down;
	while (tmp->index == (*stack)->index && tmp != (*stack))
	{
		if (tmp->value > status->max)
			status->max = tmp->value;
		if (tmp->value < status->min)
			status->min = tmp->value;
		tmp = tmp->down;
	}
	status->mid = (status->max + status->min) / 2;
}

static void	ft_next_sort_iteration(t_stack **stack_a, t_stack **stack_b,
									t_status *status)
{
	ft_rotate_to_next_pack(stack_a);
	ft_status_update(stack_a, status);
	if ((*stack_a)->value == status->min)
		(*stack_a)->index = -1;
	else if (((*stack_a)->down)->value == status->min)
	{
		ft_swap(*stack_a, 'a');
		(*stack_a)->index = -1;
	}
	else if ((status->max - status->min) > 3)
		ft_quick_sort(stack_a, stack_b, status);
	else
		ft_merge_sort(stack_a, stack_b, status);
}

/* push_swap!
 * создание стек лучше передать либо main, либо другой функции
 * stack_a, stack_b, status - можно рассматривать как одну сущность!
 * этот набор часто передается между функциями
 * 	//+скобки возможно лишние у if!
*/

void	ft_push_swap_sort(unsigned int *stack, unsigned long long length)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_status	*status;

	stack_a = NULL;
	stack_b = NULL;
	stack_a = create_stack(stack, length);
	status = (t_status *)malloc(sizeof(t_status));
	if (!status || !stack_a)
		exit (0);
	status->min = 0;
	status->max = length - 1;
	if (!ft_is_sorted(stack_a))
	{
		if (length > 6)
			while (!ft_is_sorted(stack_a))
				ft_next_sort_iteration(&stack_a, &stack_b, status);
		else if (length < 4)
			ft_simple_sort(&stack_a);
		else
			ft_merge_sort(&stack_a, &stack_b, status);
	}
	while (stack_a->value != 0)
		ft_rotate(&stack_a, 'a');
	ft_free_stack_and_status(&stack_a, &status);
}
