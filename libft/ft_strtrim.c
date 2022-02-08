/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krulindi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:04:31 by krulindi          #+#    #+#             */
/*   Updated: 2021/10/16 20:46:31 by krulindi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isvalid(char c, const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	size;
	size_t	i;
	char	*p;

	start = 0;
	i = 0;
	if (s1 == (void *)0)
		return ((void *)0);
	end = ft_strlen(s1);
	if (set == (void *)0)
		return (ft_strdup(s1));
	else
		size = ft_strlen(set);
	while (s1[start] != '\0' && isvalid(s1[start], set))
		start++;
	while (end != 0 && isvalid(s1[end - 1], set))
		end--;
	if (start > end || s1 == 0)
		return (ft_strdup(""));
	p = ft_substr(s1, start, end - start);
	if (p == (void *)0)
		return ((void *)0);
	return (p);
}
