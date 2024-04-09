/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:20:24 by dpoltura          #+#    #+#             */
/*   Updated: 2024/04/09 13:34:11 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_split(t_data **data)
{
	t_split	*cursor;

	cursor = (*data)->split_input;
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

	t_data	*data;

	while (1)
	{
		init_data(&data);
		ft_getenv(&data);
		ft_readline(&data);
		split_input(&data);
		index_split(&data);
		check_pipe(&data);
		check_chev(&data);
		print_split(&data);
		echo(&data);
		ft_execve(&data, argv, env);
		free_data(&data);
	}
	return (0);
}
