/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:03:17 by dpoltura          #+#    #+#             */
/*   Updated: 2024/06/10 10:11:22 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_parse.h"

void	ft_execve(t_data *data, char **envp)
{
	int	pid;

	while (data)
	{
		pid = fork();
		if (!pid && data->token == CMD)
			execve(data->path, data->arg, envp);
		else if (!pid && data->token == ECHO)
			ft_echo(data);
		waitpid(pid, NULL, 0);
		data = data->next;
	}
}
