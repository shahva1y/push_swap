/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krulindi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:01:01 by krulindi          #+#    #+#             */
/*   Updated: 2021/10/15 18:51:33 by krulindi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*p;
	size_t	i;

	i = 0;
	len1 = 0;
	len2 = 0;
	if (s1 == (void *)0 && s2 == (void *)0)
		return ((void *)0);
	if (s1 != (void *)0)
		len1 = ft_strlen(s1);
	if (s2 != (void *)0)
		len2 = ft_strlen(s2);
	p = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (p == (void *)0)
		return ((void *)0);
	ft_memcpy(p, s1, len1);
	ft_memcpy(p + len1, s2, len2);
	p[len1 + len2] = '\0';
	return (p);
}
