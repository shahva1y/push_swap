/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_commands.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krulindi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 20:08:33 by krulindi          #+#    #+#             */
/*   Updated: 2022/02/21 20:08:42 by krulindi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static void	ft_clear_buffer(char *buffer)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		buffer[i] = '\0';
		i++;
	}
}

static int	ft_isvalid(char *command)
{
	int		i;
	char	*letters;

	i = 0;
	letters = "abpsr";
	while (command[i] != '\0')
	{
		if (!ft_strchr(letters, command[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	ft_read_line(char *command)
{
	int		count;
	long	i;
	char	c;

	count = 0;
	i = 0;
	c = 'a';
	while (read(0, &c, 1) && c != '\n' && c != '\0')
	{
		if (i < 3)
		{
			command[i] = c;
			i++;
		}
		count++;
	}
	if (count > 3)
		ft_error("Error\n");
	return (count);
}

static void	ft_execute_command(char	*command,
								t_stack **stack_a, t_stack **stack_b)
{
	if (!ft_strcmp(command, "pa"))
		ft_p_stack(stack_b, stack_a);
	else if (!ft_strcmp(command, "pb"))
		ft_p_stack(stack_a, stack_b);
	else if (!ft_strcmp(command, "sa"))
		ft_s_stack((*stack_a));
	else if (!ft_strcmp(command, "sb"))
		ft_s_stack((*stack_b));
	else if (!ft_strcmp(command, "ra"))
		ft_r_stack(stack_a);
	else if (!ft_strcmp(command, "rb"))
		ft_r_stack(stack_b);
	else if (!ft_strcmp(command, "rra"))
		ft_rr_stack(stack_a);
	else if (!ft_strcmp(command, "rrb"))
		ft_rr_stack(stack_b);
	else if (!ft_strcmp(command, "ss"))
		ft_ss(stack_a, stack_b);
	else if (!ft_strcmp(command, "rr"))
		ft_rr(stack_a, stack_b);
	else if (!ft_strcmp(command, "rrr"))
		ft_rrr(stack_a, stack_b);
	else
		ft_error("Error\n");
}

void	ft_execute_commands(t_stack **stack_a, t_stack **stack_b)
{
	char	*command;

	command = (char *) malloc(5);
	if (!command)
		ft_error("Memory allocation error!\n");
	command[4] = '\0';
	ft_clear_buffer(command);
	while (ft_read_line(command))
	{
		if (!ft_isvalid(command))
			ft_error("Error\n");
		ft_execute_command(command, stack_a, stack_b);
		ft_clear_buffer(command);
	}
	free(command);
}
