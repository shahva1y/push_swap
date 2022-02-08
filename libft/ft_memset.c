/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krulindi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 13:44:28 by krulindi          #+#    #+#             */
/*   Updated: 2021/10/15 13:46:17 by krulindi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

void	*ft_memset(void *b, int c, size_t count)
{
	size_t			i;
	unsigned char	*p;

	i = 0;
	p = (unsigned char *)b;
	while (i < count)
	{
		p[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
