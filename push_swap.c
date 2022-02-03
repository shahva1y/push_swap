#include <stdio.h>
#include "push_swap.h"

void ft_increase_index(t_stack *stack)
{
	t_stack *tmp;

	tmp = stack;
	if (!stack)
		return ;
	(tmp->index)++;
	tmp = tmp->down;
	while(tmp != stack)
	{
		(tmp->index)++;
		tmp = tmp->down;
	}
}

static void ft_rotate_to_next_pack(t_stack **stack)
{
	t_stack *tmp;

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

static int ft_is_sorted(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	if (tmp->index != -1)
		return (0);
	if (tmp != tmp->down)
		tmp = tmp->down;
	while (tmp->index == -1 && tmp != stack)
		tmp = tmp->down;
	if (tmp == stack)
		return (1);
	return (0);
}

static t_stack 	*ft_last_less_element(t_stack **stack, t_status *status)
{
	t_stack	*tmp;
	t_stack *last_to_push;

	if ((*stack) == NULL)
		return (NULL);
	tmp = (*stack);
	//последний элемент на push
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

static t_stack 	*ft_last_greater_element(t_stack **stack, t_status *status)
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

static t_stack *ft_push_less(t_stack **stack_src, t_stack **stack_dst, t_status *status)
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

static void ft_push_greater(t_stack **stack_src, t_stack **stack_dst, t_status *status) // quick_sort_push()
{
	t_stack	*tmp;
	t_stack *last_to_push;

	while ((*stack_src)->value > status->mid)
		ft_push(stack_src, stack_dst, 'a');
	tmp = *stack_src; //3
	last_to_push = ft_last_greater_element(stack_src, status); //8
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
	//необходимо учесть особенности связанные с индексами
}

static void	ft_rotate_stack_to(t_stack **stack_a, t_stack *goal, t_status *status, t_stack **stack_b)
{
	//тут можно сделать акцент на более коротких путях, в обратную строну - к примеру
	//нужно оптимизировать с перебросом из стека B наименьшего элемента
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
		//write(1, "NOERROR!0\n",10);
	}
}

void push_swap(unsigned int *stack, unsigned long long length)
{
    t_stack				*stack_a;
    t_stack				*stack_b;
	t_status			*status;
	t_stack 			*tmp;
	unsigned long long index;

    stack_a = NULL;
    stack_b = NULL;
    stack_a = create_stack(stack, length);
	status = (t_status *)malloc(sizeof(t_status));
	if (!status)
		exit (0);
	status->min = 0;
	status->max = length - 1;
	while (!ft_is_sorted(stack_a))
	{
		ft_rotate_to_next_pack(&stack_a);
		ft_status_update(&stack_a, status);
		if (stack_a->value == status->min)
			stack_a->index = -1;
		else if ((stack_a->down)->value == status->min)
		{
			ft_swap(stack_a, 'a');
			stack_a->index = -1;
		}
		else if ((status->max - status->min) > 3)
		{
			tmp = ft_push_less(&stack_a, &stack_b, status);
			//тут нужно учесть момент возвращения к элементу с которого начали сравние, первый не отправленный в стек В
			//тут должна быть отдельная функция возвращения обратно, а не цикл
			// tmp - это начало пакета
			ft_status_update(&stack_b, status); // нужно учитывать, что mid значения из стека А в стеке B нет
			ft_rotate_stack_to(&stack_a, tmp, status, &stack_b);
			while (stack_b && (status->max - status->min) > 2)
			{
				//Тут есть что оптимизировать? нужно сразу отправлять в отсортированную часть элементы которые стоят уже в нужно месте!
				//Если они являются локальными минимумом для данного набора!
				//необходимо прописать такую же сортировку как и на внешнем цикле
				if (stack_b->value == status->min)
				{
					stack_b->index = -1;
					ft_push(&stack_b, &stack_a, 'a');
					ft_rotate(&stack_a, 'a');
				}
				else if ((stack_b->down)->value == status->min)
				{
					ft_swap(stack_b, 'b');
					stack_b->index = -1;
					ft_push(&stack_b, &stack_a, 'a');
					ft_rotate(&stack_a, 'a');
				}
				else if ((status->max - status->min) < 50)
					ft_index_insert_sort(&stack_b, &stack_a, 'a', status);
				else
				{
					ft_increase_index(stack_b);
					ft_push_greater(&stack_b, &stack_a, status);
				}
				ft_status_update(&stack_b, status);
			}
			//нужно исапользовать алгоритм слияния для сортировки оставшихся 6(7?) элементов
			//ft_merge_sort(&stack_b, &stack_a, status);
			//!!!  нужно пользоваться сортировкой вставкой!
			ft_index_insert_sort(&stack_b, &stack_a, 'a', status);
			//ft_insert_sort(&stack_b, &stack_a, 'a', status);
			//ft_stack_reverse_sort(&stack_b, 'b');
			//функция пуша из В методом merge sort
			//ft_stack_reverse_sort(&stack_b, 'b'); //сортировка должна быть в обратном порядке
			while (stack_b)
			{
				stack_b->index = -1;
				ft_push(&stack_b, &stack_a, 'a');
			}
		}
		else if ((status->max - status->min) == 2 || (status->max - status->min) == 3)
		{
			index = stack_a->index; //возможно, нужно это добавить в переменную status
			ft_push(&stack_a, &stack_b, 'b');
			if ((status->max - status->min) == 3) // заменить на более подходящую конструкцию
				ft_push(&stack_a, &stack_b, 'b');
			if (stack_a->value > (stack_a->down)->value && stack_b->value > (stack_b->down)->value)
				ft_both_swap(&stack_a, &stack_b);
			else if (stack_a->value > (stack_a->down)->value)
				ft_swap(stack_a, 'a');
			else if (stack_b->value > (stack_b->down)->value)
				ft_swap(stack_b, 'b');
			while (stack_b && stack_a->index == index)
			{
				if (stack_b->value < stack_a->value) {
					ft_push(&stack_b, &stack_a, 'a');
					stack_a->index = -1;
					ft_rotate(&stack_a, 'a');
				}
				else
				{
					stack_a->index = -1;
					ft_rotate(&stack_a, 'a');
				}
			}
			while (stack_b)
			{
				ft_push(&stack_b, &stack_a, 'a');
				stack_a->index = -1;
				ft_rotate(&stack_a, 'a');
			}
			while (stack_a->index == index)
			{
				stack_a->index = -1;
				ft_rotate(&stack_a, 'a');
			}
		}
		else if ((status->max - status->min) == 1)
		{
			if (stack_a->value > (stack_a->down)->value)
				ft_swap(stack_a, 'a');
			stack_a->index = -1;
			(stack_a->down)->index = -1;
		}
		else if ((status->max - status->min) == 0)
			stack_a->index = -1;
	}
	while (stack_a->value != 0)
		ft_rotate(&stack_a, 'a');
}