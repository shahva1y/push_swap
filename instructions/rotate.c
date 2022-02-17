#include "../push_swap.h"

void	ft_rotate(t_stack **stack, char stack_name)
{
	(*stack) = (*stack)->down;
	write(1, "r", 1);
	write(1, &stack_name, 1);
	write(1, "\n", 1);
}

void	ft_reverse_rotate(t_stack **stack, char stack_name)
{
	(*stack) = (*stack)->up;
	write(1, "rr", 2);
	write(1, &stack_name, 1);
	write(1, "\n", 1);
}

void	ft_both_rotate(t_stack **a, t_stack **b)
{
	(*a) = (*a)->down;
	(*b) = (*b)->down;
	write(1, "rr\n", 3);
}

void	ft_both_reverse_rotate(t_stack **a, t_stack **b)
{
	(*a) = (*a)->up;
	(*b) = (*b)->up;
	write(1, "rrr\n", 4);
}
