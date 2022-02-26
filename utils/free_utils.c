/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krulindi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 20:05:30 by krulindi          #+#    #+#             */
/*   Updated: 2022/02/21 20:05:34 by krulindi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	ft_free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (*stack)
	{
		tmp = (*stack);
		tmp = tmp->down;
		while (tmp != (*stack))
		{
			tmp = tmp->down;
			free(tmp->up);
		}
		free(tmp);
		(*stack) = NULL;
	}
}
