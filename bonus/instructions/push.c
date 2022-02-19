#include "../../push_swap.h"

static void	ft_cut_element(t_stack **src)
{
	t_stack	*element;

	element = (*src);
	if ((*src) != (*src)->down)
	{
		(*src) = (*src)->down;
		((element->up)->down) = (*src);
		(*src)->up = (element->up);
	}
	else
		(*src) = NULL;
}

static void	ft_paste_element(t_stack **dst, t_stack *element)
{
	if (*dst)
	{
		element->up = ((*dst)->up);
		element->down = (*dst);
		((*dst)->up)->down = element;
		(*dst)->up = element;
	}
	else
	{
		element->down = element;
		element->up = element;
	}
	(*dst) = element;
}

void	ft_p_stack(t_stack **src, t_stack **dst)
{
	t_stack	*element;

	if (*src)
	{
		element = (*src);
		ft_cut_element(src);
		ft_paste_element(dst, element);
	}
}
