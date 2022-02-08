#include "../push_swap.h"

int	ft_is_swap(t_stack **stack)
{
	if (((((*stack)->up)->value < ((*stack)->down)->value)
		 && ((*stack)->value < ((*stack)->up)->value))
		|| (((*stack)->value > ((*stack)->down)->value)
			&& (((*stack)->up)->value <= ((*stack)->down)->value))
		|| ((((*stack)->up)->value > (*stack)->value)
			&& ((*stack)->value > ((*stack)->down)->value)))
		return (1);
	return (0);
}

int	ft_is_rotate(t_stack **stack)
{
	if ((((*stack)->value > ((*stack)->up)->value)
		 && (((*stack)->up)->value >= ((*stack)->down)->value)))
		return (1);
	return (0);
}

int	ft_is_reverse_rotate(t_stack **stack)
{
	if (((*stack)->value < ((*stack)->down)->value)
		&& ((*stack)->value > ((*stack)->up)->value))
		return (1);
	return (0);
}