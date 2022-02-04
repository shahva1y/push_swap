#include "push_swap.h"

t_stack	*ft_last_less_element(t_stack **stack, t_status *status)
{
	t_stack	*tmp;
	t_stack	*last_to_push;

	if ((*stack) == NULL)
		return (NULL);
	tmp = (*stack);
	last_to_push = NULL;
	if ((*stack)->value <= status->mid)
		last_to_push = (*stack);
	if (tmp != tmp->down)
		tmp = tmp->down;
	while ((*stack)->index == tmp->index && (*stack) != tmp)
	{
		if (tmp->value <= status->mid)
			last_to_push = tmp;
		tmp = tmp->down;
	}
	return (last_to_push);
}

t_stack	*ft_last_greater_element(t_stack **stack, t_status *status)
{
	t_stack	*tmp;
	t_stack *last_to_push;

	if ((*stack) == NULL)
		return (NULL);
	tmp = (*stack);
	//последний элемент на push
	last_to_push = NULL;
	if ((*stack)->value > status->mid)
		last_to_push = (*stack);
	if (tmp != tmp->down)
		tmp = tmp->down;
	while ((*stack) != tmp)
	{
		if (tmp->value > status->mid)
			last_to_push = tmp;
		tmp = tmp->down;
	}
	return (last_to_push);
}

t_stack *ft_push_less(t_stack **stack_src, t_stack **stack_dst, t_status *status)
{
	t_stack	*tmp;
	t_stack *last_to_push;

	while ((*stack_src)->value <= status->mid)
		ft_push(stack_src, stack_dst, 'b');
	tmp = (*stack_src);
	last_to_push = ft_last_less_element(stack_src, status);
	//не всегда обязательно!
	if ((*stack_src) != (*stack_src)->down && (*stack_src)->index == ((*stack_src)->down)->index && last_to_push)
		ft_rotate(stack_src, 'a');
	while ((*stack_src) != tmp && (*stack_src)->index == tmp->index && last_to_push && (*stack_src) != last_to_push)
	{
		if ((*stack_src)->value <= status->mid)
			ft_push(stack_src, stack_dst, 'b');
		else
			ft_rotate(stack_src, 'a');
	}
	if (last_to_push)
		ft_push(stack_src, stack_dst, 'b');
	return (tmp);
}

void ft_push_greater(t_stack **stack_src, t_stack **stack_dst, t_status *status)
{
	t_stack	*tmp;
	t_stack *last_to_push;

	while ((*stack_src)->value > status->mid)
		ft_push(stack_src, stack_dst, 'a');
	tmp = *stack_src;
	last_to_push = ft_last_greater_element(stack_src, status);
	if ((*stack_src) != (*stack_src)->down && last_to_push)
		ft_rotate(stack_src, 'b');
	while ((*stack_src) != tmp && last_to_push && (*stack_src) != last_to_push)
	{
		if ((*stack_src)->value > status->mid)
			ft_push(stack_src, stack_dst, 'a');
		else
			ft_rotate(stack_src, 'b');
	}
	if (last_to_push && (*stack_src) == last_to_push)
		ft_push(stack_src, stack_dst, 'a');
}