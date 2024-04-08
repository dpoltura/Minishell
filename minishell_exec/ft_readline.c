/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:03:57 by dpoltura          #+#    #+#             */
/*   Updated: 2024/03/21 17:06:00 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_readline(t_data **data)
{
	char	*user;
	char	*pwd;
	t_env	*head;

	head = (*data)->env_vars;
	while (!ft_strcmp((*data)->env_vars->var, "USER"))
		(*data)->env_vars = (*data)->env_vars->next;
	user = (*data)->env_vars->var_content;
	(*data)->env_vars = head;
	while (!ft_strcmp((*data)->env_vars->var, "PWD"))
		(*data)->env_vars = (*data)->env_vars->next;
	pwd = (*data)->env_vars->var_content;
	(*data)->env_vars = head;
	printf(ANSI_BOLDWHITE ANSI_BLACK_BACKGROUND " 💀 MINISHELL " ANSI_RESET);
	printf(ANSI_BLACK ANSI_GREEN_BACKGROUND "" ANSI_RESET);
	printf(ANSI_GREEN_BACKGROUND " %s " ANSI_RESET, user);
	printf(ANSI_GREEN ANSI_BLUE_BACKGROUND "" ANSI_RESET);
	printf(ANSI_BLUE_BACKGROUND " %s " ANSI_RESET, pwd);
	printf(ANSI_BLUE "" ANSI_RESET);
	(*data)->input = readline(" ");
}
