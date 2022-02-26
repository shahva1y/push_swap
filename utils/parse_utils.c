/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krulindi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 20:05:42 by krulindi          #+#    #+#             */
/*   Updated: 2022/02/21 20:05:46 by krulindi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

unsigned long long	ft_get_arguments_count(char ***arguments)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (arguments[i])
	{
		j = 0;
		while (arguments[i][j])
			j++;
		count += j;
		i++;
	}
	return (count);
}

char	***ft_collect_arguments(int argc, char **argv)
{
	char			***arguments;
	int				i;

	arguments = (char ***)ft_calloc(argc, sizeof(char **));
	if (!arguments)
		ft_error("Malloc error!\n");
	i = 0;
	while (i < argc - 1)
	{
		arguments[i] = ft_split(argv[i + 1], ' ');
		if (!(arguments[i]))
		{
			ft_free_arguments(&arguments);
			ft_error("Memory allocation error!\n");
		}
		if (!(arguments[i][0]))
		{
			ft_free_arguments(&arguments);
			ft_error("Error\n");
		}
		i++;
	}
	return (arguments);
}

int	*ft_to_int(unsigned long long count, char ***arguments)
{
	int	i;
	int	j;
	int	k;
	int	*tmp;

	i = 0;
	k = 0;
	tmp = malloc(sizeof(int) * (count));
	if (!tmp)
		return (NULL);
	while (arguments[i])
	{
		j = 0;
		while (arguments[i][j])
		{
			if (!ft_is_representable(arguments[i][j]))
				ft_error_arguments(&arguments, &tmp);
			tmp[k] = ft_atoi(arguments[i][j]);
			k++;
			j++;
		}
		i++;
	}
	return (tmp);
}

t_stack	*ft_parse_arguments(int argc, char **argv)
{
	char				***arguments;
	unsigned int		*stack;
	int					*tmp;
	unsigned long long	length;

	arguments = ft_collect_arguments(argc, argv);
	length = ft_get_arguments_count(arguments);
	stack = malloc(sizeof(unsigned int) * (length));
	if (!stack)
	{
		ft_free_arguments(&arguments);
		ft_error("Memory allocation error!\n");
	}
	tmp = ft_to_int(length, arguments);
	if (!tmp)
	{
		ft_free_arguments(&arguments);
		ft_error("Memory allocation error!\n");
	}
	if (ft_duplicate_exist(tmp, length))
		ft_error_arguments(&arguments, &tmp);
	ft_free_arguments(&arguments);
	ft_index(&tmp, stack, length);
	return (create_stack(stack, length));
}
