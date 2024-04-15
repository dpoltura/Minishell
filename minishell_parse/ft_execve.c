/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:03:17 by dpoltura          #+#    #+#             */
/*   Updated: 2024/04/15 18:03:28 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_parse.h"

void	ft_execve(t_data *data, char **envp)
{
	int	pid;
	pid = fork();
	if (!pid && data->token == CMD)
		execve(data->path, data->arg, envp);
	waitpid(pid, NULL, 0);
}
