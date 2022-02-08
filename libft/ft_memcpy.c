/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krulindi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 13:49:17 by krulindi          #+#    #+#             */
/*   Updated: 2021/10/16 19:58:55 by krulindi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*pdst;
	const unsigned char	*psrc;

	i = 0;
	pdst = (unsigned char *)dst;
	psrc = (const unsigned char *)src;
	if (pdst == (void *)0 && psrc == (void *)0)
		return (dst);
	while (i < n)
	{
		pdst[i] = psrc[i];
		i++;
	}
	return (dst);
}
