/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_chev.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 10:20:30 by dpoltura          #+#    #+#             */
/*   Updated: 2024/04/09 13:15:57 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	*check_left_chev(t_data **data)
{
	t_split	*cursor;
	char	*msg;
	int	i;

	cursor = (*data)->split_input;
	i = 0;
	while (cursor)
	{
		while (cursor->content[i] == '<')
			i++;
		if (i > 3 || (count_split(data) == 1 && i > 0)
			|| (cursor->index == 1 && i > 3)
			|| (!cursor->next && i > 0))
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

static void	*check_right_chev(t_data **data)
{
	t_split	*cursor;
	char	*msg;
	int	i;

	cursor = (*data)->split_input;
	i = 0;
	while (cursor)
	{
		while (cursor->content[i] == '>')
			i++;
		if (i > 2 || (count_split(data) == 1 && i > 0)
			|| (cursor->index == 1 && i > 2)
			|| (!cursor->next && i > 0))
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

void	check_chev(t_data **data)
{
	check_left_chev(data);
	check_right_chev(data);
}
