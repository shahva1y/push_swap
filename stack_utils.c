#include "push_swap.h"

t_stack *create_stack(unsigned int *array, unsigned int length)
{
	int i;
	t_stack *stack;
	t_stack *element;

	i = 0;
	stack = NULL;
	while(i < length)
	{
		element = (t_stack *)malloc(sizeof(t_stack));
		if (!element)
		{
			//ft_free(array);
			//или exit(0);
			//функция очистки списка
			return (NULL);
		}
		if (stack)
        {
            element->up = stack->up;
            (stack->up)->down = element;
            element->down = stack;
            stack->up = element;
        }
        else
        {
            stack = element;
            element->up = stack;
            element->down = stack;
        }
		element->index = 0;
		element->value = array[i];
		i++;
	}
	free(array);
	return (stack);
}

void ft_swap(t_stack *stack, char stack_name)
{
	unsigned int value;

	value = stack->value;
	stack->value = (stack->down)->value;
	(stack->down)->value = value;
	write(1, "s", 1);
	write(1, &stack_name, 1);
	write(1, "\n", 1);
}

void ft_rotate(t_stack **stack, char stack_name)
{
	(*stack) = (*stack)->down;
	write(1, "r", 1);
	write(1, &stack_name, 1);
	write(1, "\n", 1);
}

void ft_reverse_rotate(t_stack **stack, char stack_name)
{
	(*stack) = (*stack)->up;
	write(1, "rr", 2);
	write(1, &stack_name, 1);
	write(1, "\n", 1);
}

void ft_push(t_stack **src, t_stack **dst, char dst_name)
{
	t_stack *tmp;
	t_stack *down;
	t_stack *up;

     if (!src)
        return;
	tmp = (*src);
    if ((*src) != (*src)->down)
    {
        (*src) = (*src)->down;
        ((tmp->up)->down) = (*src);
        (*src)->up = (tmp->up);
    }
    else
        (*src) = NULL;
	if (*dst)
	{
		down = (*dst);
		up = (*dst)->up;
		up->down = tmp;
		down->up = tmp;
		tmp->down = down;
		tmp->up = up;
		(*dst) = tmp;
	}
	else
	{
		tmp->down = tmp;
		tmp->up = tmp;
		(*dst) = tmp;
	}
	write(1, "p", 1);
	write(1, &dst_name, 1);
	write(1, "\n", 1);
}

void ft_stack_sort(t_stack **stack, char stack_name)
{
	if (((((*stack)->up)->value <= ((*stack)->down)->value)
			&& ((*stack)->value < ((*stack)->up)->value))
		|| (((*stack)->value > ((*stack)->down)->value)
			&& (((*stack)->up)->value <= ((*stack)->down)->value))
		|| ((((*stack)->up)->value > (*stack)->value)
			&& ((*stack)->value > ((*stack)->down)->value)))
		ft_swap(*stack, stack_name);
	if (((*stack)->value > ((*stack)->up)->value)
		&& (((*stack)->up)->value >= ((*stack)->down)->value))
		ft_rotate(stack, stack_name);
	if (((*stack)->value < ((*stack)->down)->value)
		&& (*stack)->value > ((*stack)->up)->value)
		ft_reverse_rotate(stack, stack_name);
}

unsigned long long	ft_get_stack_length(t_stack *stack)
{
	unsigned long long	length;
	t_stack *tmp;

	tmp = stack;
	length = 0;
	if (!stack)
		return (length);
	if (tmp != tmp->down)
		tmp = tmp->down;
	length++;
	while (tmp != stack)
	{
		tmp = tmp->down;
		length++;
	}
	return (length);
}

void ft_both_rotate(t_stack **a, t_stack **b)
{
	(*a) = (*a)->down;
	(*b) = (*b)->down;
	write(1, "rr\n", 3);
}

void ft_both_reverse_rotate(t_stack **a, t_stack **b)
{
	(*a) = (*a)->up;
	(*b) = (*b)->up;
	write(1, "rrr\n", 4);
}

void ft_both_swap(t_stack **a, t_stack **b)
{
	unsigned int value;

	value = (*a)->value;
	(*a)->value = ((*a)->down)->value;
	((*a)->down)->value = value;
	value = (*b)->value;
	(*b)->value = ((*b)->down)->value;
	((*b)->down)->value = value;
	write(1, "ss\n", 3);
}