/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krulindi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 14:56:50 by krulindi          #+#    #+#             */
/*   Updated: 2021/10/15 15:00:43 by krulindi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	size;
	size_t	i;

	i = 0;
	if (s == (void *)0)
		return ((void *)0);
	size = ft_strlen(s);
	if (start > size)
		len = 0;
	if (len > size - (size_t)start && len != 0)
		len = size - (size_t)start;
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (p == (void *)0)
		return ((void *)0);
	while (i < len)
	{
		p[i] = (char)s[(size_t)start + i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
