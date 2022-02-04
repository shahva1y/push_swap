#include "../push_swap.h"

//поменять название, не освещает в полной мере цель функции
static void	ft_rotate_stack_to(t_stack **stack_a, t_stack *goal, t_status *status, t_stack **stack_b)
{
	if ((goal->up)->index != -1)
		return ;
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

static void	ft_return_to_stack_a(t_stack **stack_b, t_stack **stack_a, t_status *status)
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
		ft_increase_index((*stack_b));
		ft_index_insert_sort(stack_b, stack_a, 'a');
	}
	else
	{
		ft_increase_index((*stack_b));
		ft_push_greater(stack_b, stack_a, status);
	}
}

//необходимо подобрать другое название, алгоритм quick_sort внутри этой функции реализован
//мб и удачное, изменен лишь механизм возврата из стека B,
void	ft_quick_sort(t_stack **stack_a, t_stack **stack_b, t_status *status)
{
	t_stack *tmp; //возможно лишняя переменная, нет необходимости ее сохранять!
	//возможно есть другие критерии поиска начала пакета

	tmp = ft_push_less(stack_a, stack_b, status);
	ft_status_update(stack_b, status); // нужно учитывать, что mid значения из стека А в стеке B нет
	//тут нужно учесть момент возвращения к элементу с которого начали сравние, первый не отправленный в стек В
	//тут должна быть отдельная функция возвращения обратно, а не цикл
	// tmp - это начало пакета
	ft_rotate_stack_to(stack_a, tmp, status, stack_b);
	while ((*stack_b))
	{
		ft_return_to_stack_a(stack_b, stack_a, status);
		ft_status_update(stack_b, status);
	}
}