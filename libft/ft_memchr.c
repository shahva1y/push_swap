/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krulindi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 14:09:53 by krulindi          #+#    #+#             */
/*   Updated: 2021/10/15 14:12:12 by krulindi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*p;

	i = 0;
	p = (const unsigned char *) s;
	while (i < n)
	{
		if (p[i] == (unsigned char) c)
			return ((void *)&p[i]);
		i++;
	}
	return ((void *)0);
}
