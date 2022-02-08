/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krulindi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:07:43 by krulindi          #+#    #+#             */
/*   Updated: 2021/10/17 16:14:29 by krulindi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	removep(char **p)
{
	size_t	i;

	i = 0;
	while (p[i] != (void *)0)
	{
		free(p[i]);
		i++;
	}
	free(p);
}

static size_t	strcount(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if ((s[i] != c && s[i + 1] == c)
			|| (s[i] != c && s[i + 1] == '\0'))
			count++;
		i++;
	}	
	return (count);
}

static char	*wordcut(const char **str, char c)
{
	const char	*s;
	char		*word;
	int			len;
	int			i;

	s = *str;
	len = 0;
	i = 0;
	while (s[i] == c)
		i++;
	while (s[i + len] != c && s[i + len] != '\0')
		len++;
	word = ft_substr(s, i, len);
	*str += (len + i);
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**p;
	size_t	count;
	size_t	i;

	i = 0;
	if (s == (void *)0)
		return ((void *)0);
	count = strcount(s, c);
	p = (char **)malloc((count + 1) * sizeof(char *));
	if (p == (void *)0)
		return ((void *)0);
	p[count] = (void *)0;
	while (i < count && count != 0)
	{
		p[i] = wordcut(&s, c);
		if (p[i] == (void *)0)
		{
			removep(p);
			return ((void *)0);
		}
		i++;
	}
	return (p);
}
