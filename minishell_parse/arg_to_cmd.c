/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_to_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:51:14 by dpoltura          #+#    #+#             */
/*   Updated: 2024/04/11 14:40:11 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_parse.h"

static void	free_data_arg(t_data *data)
{
	free(data->value);
	free(data);
}

void	arg_to_cmd(t_data *data)
{
	t_data	*cmd;
	t_data	*tmp;
	int		i;
	
	while (data)
	{
		i = 1;
		while (data->next && data->next->token != ARG)
			data = data->next;
		if (!data || !data->next)
			return ;
		cmd = data;
		cmd->arg = malloc(sizeof(char *) * 255);
		cmd->arg[0] = ft_strdup(cmd->value);
		tmp = data->next;
		while (tmp && tmp->token == ARG)
		{
			cmd->arg[i] = ft_strdup(tmp->value);
			data->next = data->next->next;
			free_data_arg(tmp);
			tmp = data->next;
			i++;
		}
		cmd->arg[i] = NULL;
	}
}
