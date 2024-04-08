/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:46:44 by dpoltura          #+#    #+#             */
/*   Updated: 2024/03/22 14:26:02 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_input(t_data **data)
{
	t_split	*cursor;

	cursor = (*data)->split_input;
	printf(ANSI_BOLDGREEN "\nINPUT:\n" ANSI_RESET);
	while (cursor)
	{
		printf("%s", cursor->content);
		cursor = cursor->next;
		if (cursor)
			printf(", ");
	}
	printf("\n\n");
}

void	print_env_split_var(t_data **data)
{
	t_env	*env_vars;
	t_split	*var_split_content;

	env_vars = (*data)->env_vars;
	var_split_content = (*data)->env_vars->var_split_content;
	while (env_vars)
	{
		printf(ANSI_BOLDGREEN "VAR:\n" ANSI_RESET "%s\n", env_vars->var);
		if (env_vars->var_content)
			printf(ANSI_BOLDYELLOW "CONTENT:\n" ANSI_RESET "%s\n", env_vars->var_content);
		printf(ANSI_BOLDRED "SPLIT CONTENT:\n" ANSI_RESET);
		while (var_split_content)
		{
			printf("%s\n", var_split_content->content);
			var_split_content = var_split_content->next;
		}
		printf("\n");
		env_vars = env_vars->next;
		if (env_vars)
			var_split_content = env_vars->var_split_content;
	}
}
