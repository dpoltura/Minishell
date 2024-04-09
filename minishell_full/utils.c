/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:51:45 by dpoltura          #+#    #+#             */
/*   Updated: 2024/04/09 13:13:52 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != 0)
		i++;
	return (i);
}

char	*ft_strdup(const char *src)
{
	int		s;
	int		len;
	char	*dest;

	s = 0;
	len = ft_strlen(src);
	dest = malloc(sizeof(char) * (len + 1));
	if (dest == 0)
		return (0);
	while (src[s] != '\0')
	{
		dest[s] = src[s];
		s++;
	}
	dest[s] = '\0';
	return (dest);
}

void	index_split(t_data **data)
{
	t_split	*cursor;
	int	i;

	cursor = (*data)->split_input;
	i = 1;
	while (cursor)
	{
		cursor->index = i;
		cursor = cursor->next;
		i++;
	}
}

int	count_split(t_data **data)
{
	t_split	*cursor;
	int	i;

	cursor = (*data)->split_input;
	i = 0;
	while (cursor)
	{
		cursor = cursor->next;
		i++;
	}
	return (i);
}

int	ft_strcmp(char *src, char *cmp)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (src[i] && cmp[j] && src[i] == cmp[j])
	{
		i++;
		j++;
	}
	if (!src[i] && !cmp[j])
		return (1);
	return (0);
}

t_env	*get_var(char *var, t_data **data)
{
	t_env	*cursor;

	cursor = (*data)->env_vars;
	while (!ft_strcmp(cursor->var, var))
		cursor = cursor->next;
	return (cursor);
}
