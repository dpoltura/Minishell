/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:20:24 by dpoltura          #+#    #+#             */
/*   Updated: 2024/04/09 10:49:47 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_split(t_split *split)
{
	t_split	*cursor;

	cursor = split;
	while (cursor)
	{
		printf("content: [ %s ] index: [ %d ]\n", cursor->content, cursor->index);
		cursor = cursor->next;
	}
}

int	main(int argc, char **argv, char **env)
{
	(void) argc;
	(void) **argv;
	(void) **env;

	t_split	*split;
	char	*line;

	init_split(&split);
	line = readline("> ");
	split_line(split, line);
	index_split(split);
	check_pipe(split, line);
	check_chev(split, line);
	print_split(split);
	free_split(split);
	free(line);
	return (0);
}
