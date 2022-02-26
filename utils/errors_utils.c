/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krulindi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 19:30:01 by krulindi          #+#    #+#             */
/*   Updated: 2022/02/24 19:30:07 by krulindi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_error(char *error_messege)
{
	write(2, error_messege, ft_strlen(error_messege));
	exit(1);
}

void	ft_error_arguments(char ****arguments, int **tmp)
{
	ft_free_arguments(arguments);
	free(*tmp);
	ft_error("Error\n");
}
