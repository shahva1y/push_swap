/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krulindi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 14:14:09 by krulindi          #+#    #+#             */
/*   Updated: 2021/10/15 14:17:07 by krulindi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isvalid(const char *needle, const char *other, size_t max)
{
	size_t	i;

	i = 0;
	while (needle[i] != '\0' && other[i] != '\0'
		&& needle[i] == other[i] && i < max)
		i++;
	if (needle[i] == '\0')
		return (1);
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		if (haystack[i] == needle[0]
			&& isvalid(needle, &haystack[i], len - i))
			return ((char *)&haystack[i]);
		i++;
	}	
	return ((void *)0);
}
