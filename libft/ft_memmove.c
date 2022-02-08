/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krulindi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 13:51:22 by krulindi          #+#    #+#             */
/*   Updated: 2021/10/16 19:58:40 by krulindi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*pdst;
	unsigned char	*psrc;

	pdst = (unsigned char *)dst;
	psrc = (unsigned char *)src;
	i = 0;
	if (pdst == (void *)0 && psrc == (void *)0)
		return (dst);
	if (dst <= src)
	{
		ft_memcpy(dst, src, len);
		return (dst);
	}
	while (i < len)
	{
		pdst[len - 1 - i] = psrc[len - 1 - i];
		i++;
	}
	return (dst);
}
