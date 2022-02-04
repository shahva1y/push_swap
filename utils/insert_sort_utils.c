#include "../push_swap.h"

unsigned long long	ft_rotate_count_to_find(t_stack *element, t_stack *stack)
{
	t_stack	*tmp;
	unsigned long long	count;

	tmp = stack;
	count = 0;
	while (tmp != element)
	{
		count++;
		tmp = tmp->down;
	}
	return (count);
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
	while (element->value < stack->value && (stack->up)->index == element->index && stack->index == element->index)
	{
		count++;
		stack = stack->up;
	}
	return (count);
}

void ft_change_elements_index(t_stack *stack) //sorted_index???
{
	t_stack				*tmp;
	unsigned long long	index;

	tmp = stack;
	index = stack->index;
	while (tmp != tmp->up && (tmp->up)->index == index)
		tmp = tmp->up;
	while (tmp->index == index)
	{
		tmp->index  = -1;
		tmp = tmp->down;
	}
}