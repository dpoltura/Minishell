/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_to_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduriez <aduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:51:14 by dpoltura          #+#    #+#             */
/*   Updated: 2024/06/24 13:54:25 by aduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	arg_to_cmd(t_data *data)
{
	t_data *cmd;
	t_data *tmp;
	t_data *full_tmp;
	int i;

	cmd = data;
	tmp = data;
	if (data->next == NULL)
		return;
	while(data)
	{
		if (data->token == CMD)
		{
			i = 1;
			cmd->arg = malloc(sizeof(char *) * 255);
			if (data->next != NULL)
				tmp = data->next;
				
			cmd->arg[0] = strdup(cmd->value);
			if (data->next == NULL)
			{
				cmd->arg[1]= NULL;
			}
			while (tmp != NULL && (tmp->token == INFILE || tmp->token == CMD
					|| tmp->token == ARG))
			{
				cmd->arg[i] = strdup(tmp->value);
				tmp = data;
				if (tmp->next->next == NULL)
				{
					full_tmp = data;
					data = full_tmp;
					free(data->next);
					data->next = NULL;
				}
				else
				{
					full_tmp = data->next->next;
					free(data->next);
					data->next = full_tmp;
				}
				tmp = data;
				tmp = tmp->next;
				i++;
			}
			cmd->arg[i] = NULL;
		}
		if (data->token == PIPE)
		{
			tmp = data->next;
			cmd = data;
			i = 0;
			cmd->arg = malloc(sizeof(char *) * 255);
			while (tmp != NULL && (tmp->token == INFILE || tmp->token == CMD
					|| tmp->token == ARG))
			{
				cmd->arg[i] = strdup(tmp->value);
				if (i == 0)
					data->path = tmp->path;
				i++;
				tmp = data;
				if (tmp->next->next == NULL)
				{
					full_tmp = data;
					data = full_tmp;
					free(data->next);
					data->next = NULL;
				}
				else
				{
					full_tmp = data->next->next;
					free(data->next);
					data->next = full_tmp;
				}
				tmp = data;
				tmp = tmp->next;
			}
			cmd->arg[i] = NULL;
		}
		data = data->next;
	}
}