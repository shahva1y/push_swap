#include "../push_swap.h"

void	ft_swap(t_stack *stack, char stack_name)
{
	unsigned int	value;

	value = stack->value;
	stack->value = (stack->down)->value;
	(stack->down)->value = value;
	write(1, "s", 1);
	write(1, &stack_name, 1);
	write(1, "\n", 1);
}

void	ft_both_swap(t_stack **a, t_stack **b)
{
	unsigned int	value;

	value = (*a)->value;
	(*a)->value = ((*a)->down)->value;
	((*a)->down)->value = value;
	value = (*b)->value;
	(*b)->value = ((*b)->down)->value;
	((*b)->down)->value = value;
	write(1, "ss\n", 3);
}
