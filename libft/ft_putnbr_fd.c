/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krulindi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:23:08 by krulindi          #+#    #+#             */
/*   Updated: 2021/10/17 16:20:30 by krulindi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	smbl;
	int		quo;
	int		rem;

	if (fd < 0)
		return ;
	quo = n;
	rem = quo % 10;
	quo = quo / 10;
	if (rem < 0)
	{
		quo *= -1;
		rem *= -1;
		write(fd, "-", 1);
	}
	if (quo != 0)
		ft_putnbr_fd(quo, fd);
	smbl = '0' + rem;
	write(fd, &smbl, 1);
}
