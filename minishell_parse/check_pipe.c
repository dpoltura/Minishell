/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:05:57 by dpoltura          #+#    #+#             */
/*   Updated: 2024/04/09 10:16:39 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*check_pipe(t_split *split, char *line)
{
	t_split	*cursor;
	char	*msg;
	int	i;

	cursor = split;
	i = 0;
	while (cursor)
	{
		while (cursor->content[i] == '|')
			i++;
		if (cursor->index == 1 && i > 0)
		{
			msg = ft_strdup("minishell: syntax error");
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
