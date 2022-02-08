/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krulindi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:11:59 by krulindi          #+#    #+#             */
/*   Updated: 2021/10/15 15:47:01 by krulindi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*tostr(char *p, int n)
{
	int	quo;
	int	rem;

	quo = n;
	rem = quo % 10;
	quo = quo / 10;
	if (rem < 0)
	{
		quo *= -1;
		rem *= -1;
		*p = '-';
		p++;
	}	
	if (quo != 0)
		p = tostr(p, quo);
	*p = '0' + rem;
	return (++p);
}

char	*ft_itoa(int n)
{
	char	*p;
	int		bit;
	int		quo;

	quo = n;
	bit = 0;
	if (quo <= 0)
		bit++;
	while (quo)
	{
		quo = quo / 10;
		bit++;
	}
	p = malloc((bit + 1) * sizeof(char));
	if (p == (void *)0)
		return ((void *)0);
	tostr(p, n);
	p[bit] = '\0';
	return (p);
}
