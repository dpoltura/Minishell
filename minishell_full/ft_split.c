/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:11:28 by dpoltura          #+#    #+#             */
/*   Updated: 2024/03/20 07:45:39 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	ft_check_input(char const *s, unsigned int start, size_t len)
{
	if (start > ft_strlen(s))
		return (len = 0);
	if (len > ft_strlen(s) - start)
		return (len = ft_strlen(s) - start);
	return (len);
}

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;
	size_t	j;
	size_t	size;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	size = ft_check_input(s, start, len);
	ptr = malloc(sizeof(char) * (size + 1));
	if (!ptr)
		return (NULL);
	while (s[i] != '\0')
	{
		if (i >= start && j < len)
		{
			ptr[j] = s[i];
			j++;
		}
		i++;
	}
	ptr[j] = '\0';
	return (ptr);
}

static int	count_words(char const *s, char c)
{
	int	c_w;
	int	tmp;

	tmp = 0;
	c_w = 0;
	while (*s != '\0')
	{
		if (tmp == 1 && *s == c)
			tmp = 0;
		if (tmp == 0 && *s != c)
		{
			tmp = 1;
			c_w++;
		}
		s++;
	}
	return (c_w);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	int		i;
	int		x;

	x = 0;
	if (!s)
		return (NULL);
	dest = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!dest)
		return (NULL);
	while (*s)
	{
		if (s[0] == c)
			s++;
		else
		{
			i = 0;
			while (s[i] != '\0' && s[i] != c)
				i++;
			dest[x++] = ft_substr(s, 0, i);
			s = s + i;
		}
	}
	dest[x] = NULL;
	return (dest);
}
