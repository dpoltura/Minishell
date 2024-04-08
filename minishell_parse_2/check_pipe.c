/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:05:57 by dpoltura          #+#    #+#             */
/*   Updated: 2024/03/28 13:38:12 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*pipe_error(int i)
{
	char	*msg;

	msg = ft_strdup("minishell: syntax error near unexpected token `");
	while (i > 3)
	{
		msg = ft_strjoin(msg, "|");
		i--;
	}
	msg = ft_strjoin(msg, "'");
	return (msg);
}

char	*check_pipe(t_split *split, char *line)
{
	t_split	*cursor;
	char	*msg;
	int	i;

	cursor = split;
	i = 0;
	while (cursor)
	{
		while (cursor->content[i++] == '|');
		if (i > 3)
		{
			msg = pipe_error(i);
			printf("%s\n", msg);
			free(msg);
			free_split(split);
			free(line);
			exit(2);
		}
		cursor = cursor->next;
		i = 0;
	}
	return (NULL);
}
