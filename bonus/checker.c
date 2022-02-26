/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krulindi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 20:08:54 by krulindi          #+#    #+#             */
/*   Updated: 2022/02/21 20:08:57 by krulindi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static int	ft_sorted_check(t_stack *stack_a, t_stack *stack_b)
{
	int	result;

	result = ((stack_a->value == 0) || (stack_b == NULL)
			|| ft_is_sorted(stack_a));
	return (result);
}

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc > 1)
	{
		stack_a = ft_parse_arguments(argc, argv);
		ft_execute_commands(&stack_a, &stack_b);
		if (ft_sorted_check(stack_a, stack_b))
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
		ft_free_stack(&stack_a);
		ft_free_stack(&stack_b);
	}
	return (0);
}
