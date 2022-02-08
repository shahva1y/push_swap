/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krulindi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:15:09 by krulindi          #+#    #+#             */
/*   Updated: 2021/10/15 15:16:32 by krulindi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*p;
	size_t	size;
	size_t	i;

	if (s == (void *)0)
		return ((void *)0);
	size = ft_strlen(s);
	p = malloc(sizeof(char) * (size + 1));
	if (p == (void *)0)
		return ((void *)0);
	i = 0;
	while (i < size)
	{
		p[i] = (*f)(i, s[i]);
		i++;
	}
	p[i] = '\0';
	return (p);
}
