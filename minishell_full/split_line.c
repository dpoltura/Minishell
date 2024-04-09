/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:49:13 by dpoltura          #+#    #+#             */
/*   Updated: 2024/03/27 15:49:25 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	if_limiter(char *line, int i, char *ptr, t_split **cursor)
{
	while (line[i] == '|' || line[i] == '<' || line[i] == '>')
	{
		ptr[0] = line[i];
		ptr[1] = '\0';
		(*cursor)->content = ft_strjoin((*cursor)->content, ptr);
		i++;
		if (line[i] != line[i - 1])
			break ;
	}
	if (line[i])
	{
		(*cursor)->next = malloc(sizeof(t_split));
		(*cursor) = (*cursor)->next;
		(*cursor)->content = NULL;
	}
	return (i);
}

static int	if_not_limiter(char *line, int i, char *ptr, t_split **cursor)
{
	while (line[i] && line[i] != '|' && line[i] != '<' && line[i] != '>' && line[i] != ' ')
	{
		ptr[0] = line[i];
		ptr[1] = '\0';
		(*cursor)->content = ft_strjoin((*cursor)->content, ptr);
		i++;
	}
	if (line[i])
	{
		(*cursor)->next = malloc(sizeof(t_split));
		(*cursor) = (*cursor)->next;
		(*cursor)->content = NULL;
	}
	return (i);
}

void	split_line(t_split *split, char *line)
{
	t_split	*cursor;
	char	ptr[2];
	int	i;

	cursor = split;
	i = 0;
	while (line[i])
	{
		while (line[i] == ' ')
			i++;
		if (line[i] && (line[i] == '|' || line[i] == '<' || line[i] == '>'))
			i = if_limiter(line, i, ptr, &cursor);
		else if (line[i] && line[i] != '|' && line[i] != '<' && line[i] != '>')
			i = if_not_limiter(line, i, ptr, &cursor);
		cursor->next = NULL;
	}
}
