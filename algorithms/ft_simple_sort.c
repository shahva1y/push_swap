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