/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:20:24 by dpoltura          #+#    #+#             */
/*   Updated: 2024/03/28 13:31:43 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_split(t_split *split)
{
	t_split	*cursor;

	cursor = split;
	while (cursor)
	{
		printf("%s\n", cursor->content);
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

	split = malloc(sizeof(t_split));
	split->content = NULL;
	split->next = NULL;
	line = readline("> ");
	split_line(split, line);
	check_pipe(split, line);
	print_split(split);
	free_split(split);
	free(line);
	return (0);
}
