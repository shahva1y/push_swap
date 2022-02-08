/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krulindi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 14:34:53 by krulindi          #+#    #+#             */
/*   Updated: 2021/10/15 14:39:40 by krulindi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	size_t	i;
	char	*p;

	i = 0;
	len = ft_strlen(s1);
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (p == (void *)0)
		return ((void *)0);
	while (i <= len)
	{
		p[i] = s1[i];
		i++;
	}
	return (p);
}
