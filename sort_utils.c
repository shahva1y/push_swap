#include "push_swap.h"

//нужно проверить сортировку этим алгортмом пока упрощенно, потом только добавться в основной код
static void	ft_push_next_element(t_stack **src, t_stack **dst, t_stack *element)
{
	t_stack	*tmp;
	unsigned long long	length;
	unsigned long long	count;

	if (!(*src) || !element)
		return ;
	tmp = *src;
	count = 0;
	while (tmp != element)
	{
		count++;
		tmp = tmp->down;
	}
	length = ft_get_stack_length(*src);
	if (count > length / 2)
	{
		while ((*src) != element
			&& element->value < (*dst)->value && element->value < ((*dst)->up)->value
			&& ((*dst)->up)->index == element->index && (*dst)->index == element->index)
			ft_both_reverse_rotate(src, dst);
		while ((*src) != element)
			ft_reverse_rotate(src, 'b');
	}
	else
	{
		while ((*src) != element
			   && element->value > (*dst)->value && (*dst)->index == element->index)
			ft_both_rotate(src, dst);
		while ((*src) != element)
			ft_rotate(src, 'b');
	}
	while (element->value > (*dst)->value
		&& (*dst)->index == element->index)
		ft_rotate(dst, 'a');
	while (element->value < (*dst)->value && element->value < ((*dst)->up)->value
		&& ((*dst)->up)->index == element->index && (*dst)->index == element->index)
		ft_reverse_rotate(dst, 'a');
	ft_push(src, dst, 'a');
}

static unsigned long long	ft_rotate_count(t_stack *element, t_stack *dst)
{
	unsigned long long	count;

	count = 0;
	while (element->value > dst->value && dst->index == element->index)
	{
		count++;
		dst = dst->down;
	}
	while (element->value < dst->value && (dst->up)->index == element->index && dst->index == element->index)
	{
		count++;
		dst = dst->up;
	}
	return (count);
}

void	ft_index_insert_sort(t_stack **src, t_stack **dst, char stack_name, t_status *status)
{
	t_stack *tmp;
	t_stack *next;
	unsigned long long steps;
	unsigned long long steps_src;
	unsigned long long steps_min;
	unsigned long long length;
	unsigned long long	index;

	//необходимо дополнительно провить на NULL
	if (!(*src))
		return ;
	ft_increase_index(*src); //обязательная часть при внедрении в основную программу
	ft_push(src, dst, stack_name);
	length = ft_get_stack_length(*src);
	while (*src)
	{
		tmp = *src;
		steps_min = ft_rotate_count(tmp, *dst);
		next = tmp;
		tmp = tmp->down;
		steps_src = 1;
		while (tmp != *src)
		{
			//нужно учесть, что до любого элемента в стеке B, можно добаться за length/2 шагов
			steps = steps_src;
			if (steps_src > length / 2)
				steps = length - steps_src;
			steps += ft_rotate_count(tmp, *dst);
			if (steps < steps_min)
			{
				steps_min = steps;
				next = tmp;
			}
			tmp = tmp->down;
			steps_src++;
		}
		ft_push_next_element(src, dst, next);
		length--;
	}
	//расставить -1 везде
	tmp = (*dst);
	index = (*dst)->index;
	while (tmp != tmp->up && (tmp->up)->index == index)
		tmp = tmp->up;
	while (tmp->index == index)
	{
		tmp->index  = -1;
		tmp = tmp->down;
	}
}