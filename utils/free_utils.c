#include "../push_swap.h"

void	ft_free_stack_and_status(t_stack **stack, t_status **status)
{
	t_stack	*tmp;

	tmp = (*stack);
	tmp = tmp->down;
	while (tmp != (*stack))
	{
		tmp = tmp->down;
		free(tmp->up);
	}
	free(tmp);
	(*stack) = NULL;
	free((*status));
	(*status) = NULL;
}

void	ft_free_arguments(char ****arguments)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while ((*arguments)[i])
	{
		j = 0;
		while ((*arguments)[i][j])
		{
			free((*arguments)[i][j]);
			j++;
		}
		free((*arguments)[i]);
		i++;
	}
	free((*arguments));
	(*arguments) = NULL;
}
