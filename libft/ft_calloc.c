/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krulindi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 14:32:54 by krulindi          #+#    #+#             */
/*   Updated: 2021/10/15 14:34:17 by krulindi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*p;
	size_t	i;

	p = (char *)malloc(size * count);
	i = 0;
	if (p == (void *)0)
		return ((void *)0);
	while (i < size * count)
	{
		p[i] = '\0';
		i++;
	}
	return ((void *)p);
}
