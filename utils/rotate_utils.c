#include "../push_swap.h"

void	ft_reverse_rotate_to(t_stack **stack_a, t_stack **stack_b,
								t_stack *goal, t_status *status)
{
	while ((*stack_a) != goal && (*stack_b)->value != status->min)
		ft_both_reverse_rotate(stack_a, stack_b);
	while ((*stack_a) != goal)
		ft_reverse_rotate(stack_a, 'a');
	if ((*stack_b)->value == status->min)
	{
		(*stack_b)->index = -1;
		ft_push(stack_b, stack_a, 'a');
		ft_rotate(stack_a, 'a');
		ft_status_update(stack_b, status);
	}
}

void	ft_rotate_to(t_stack **stack_a, t_stack **stack_b,
						t_stack *goal, t_status *status)
{
	while ((*stack_a) != goal && (*stack_b)->value != status->min)
		ft_both_rotate(stack_a, stack_b);
	while ((*stack_a) != goal)
		ft_rotate(stack_a, 'a');
	if ((*stack_b)->value == status->min)
	{
		(*stack_b)->index = -1;
		ft_push(stack_b, stack_a, 'a');
		ft_rotate(stack_a, 'a');
		ft_status_update(stack_b, status);
	}
}

int	ft_rotate_direction(t_stack *stack, t_stack *goal)
{
	t_stack				*tmp;
	unsigned long long	i;
	unsigned long long	j;

	i = 0;
	j = 0;
	tmp = stack;
	while (tmp != goal)
	{
		tmp = tmp->down;
		i++;
	}
	tmp = stack;
	while (tmp != goal)
	{
		tmp = tmp->up;
		j++;
	}
	if (i > j)
		return (-1);
	return (1);
}
