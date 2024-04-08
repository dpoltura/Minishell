/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:15:51 by dpoltura          #+#    #+#             */
/*   Updated: 2024/03/25 10:47:30 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	check_path(t_data **data, char ***argv)
{
	char	*full_path;
	t_env	*var;
	t_split	*var_path;
	t_split	*input;

	full_path = NULL;
	var = get_var("PATH", data);
	var_path = var->var_split_content;
	input = (*data)->split_input;
	while (var_path && input)
	{
		full_path = var_path->content;
		full_path = ft_strjoin(full_path, "/");
		full_path = ft_strjoin(full_path, input->content);
		*argv = get_args((*data)->split_input, *argv);
		if (access(full_path, R_OK))
			var_path = var_path->next;
		else
		{
			input->content = full_path;
			input = input->next;
			var_path = var->var_split_content;
		}
	}
}

void	ft_execve(t_data **data, char **argv, char **env)
{
	check_path(data, &argv);
	(*data)->pid = fork();
	if ((*data)->pid == 0)
		execve((*data)->split_input->content, argv, env);
	else
		printf(ANSI_BOLDWHITE "EXEC:\n" ANSI_RESET);
	waitpid((*data)->pid, NULL, 0);
}
