/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:05:57 by dpoltura          #+#    #+#             */
/*   Updated: 2024/04/09 13:12:06 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*check_pipe(t_data **data)
{
	t_split	*cursor;
	char	*msg;
	int	i;

	cursor = (*data)->split_input;
	i = 0;
	while (cursor)
	{
		while (cursor->content[i] == '|')
			i++;
		if (i > 2 || (cursor->index == 1 && i > 0))
		{
			msg = ft_strdup("minishell: syntax error");
			printf("%s\n", msg);
			free(msg);
			free_data(data);
			exit(2);
		}
		cursor = cursor->next;
		i = 0;
	}
	return (NULL);
}
