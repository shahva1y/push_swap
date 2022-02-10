#include "../push_swap.h"

static t_stack	*ft_first_greater_element(t_stack *stack, unsigned long long mid)
{
	while (stack->value <= mid)
		stack = stack->down;
	return (stack);
}

//поменять название, не освещает в полной мере цель функции
static void	ft_comeback_to(t_stack **stack_a, t_stack *goal, t_stack **stack_b, t_status *status)
{
	if ((goal->up)->index != -1)
		return ;
	//Функция поиска min
	//Тут необходимо написать функцию оценки, альтернативных путей - в обратную сторону
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

static void	ft_next_sort_iteration(t_stack **stack_b, t_stack **stack_a, t_status *status)
{
	if ((*stack_b)->value == status->min)
	{
		(*stack_b)->index = -1;
		ft_push(stack_b, stack_a, 'a');
		ft_rotate(stack_a, 'a');
	}
	else if (((*stack_b)->down)->value == status->min)
	{
		ft_swap((*stack_b), 'b');
		(*stack_b)->index = -1;
		ft_push(stack_b, stack_a, 'a');
		ft_rotate(stack_a, 'a');
	}
	else if ((status->max - status->min) < 50)
	{
		ft_increase_index((*stack_b)); //!
		ft_insert_sort(stack_b, stack_a, 'a');
	}
	else
	{
		ft_increase_index((*stack_b)); //!
		ft_push_greater(stack_b, stack_a, status);
	}
}

//необходимо подобрать другое название, алгоритм quick_sort внутри этой функции реализован
//мб и удачное, изменен лишь механизм возврата из стека B,
void	ft_quick_sort(t_stack **stack_a, t_stack **stack_b, t_status *status)
{
	t_stack *great_half_start;

	great_half_start = ft_first_greater_element(*stack_a, status->mid);
	ft_push_less(stack_a, stack_b, status);
	ft_status_update(stack_b, status);
	ft_comeback_to(stack_a, great_half_start, stack_b, status);
	while ((*stack_b))
	{
		ft_next_sort_iteration(stack_b, stack_a, status); //??? static! поэтому не страшно совпадение имен
		ft_status_update(stack_b, status);
	}
}