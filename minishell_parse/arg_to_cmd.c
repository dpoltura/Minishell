/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_to_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:51:14 by dpoltura          #+#    #+#             */
/*   Updated: 2024/04/11 12:41:52 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_parse.h"

void	arg_to_cmd(t_data *data)
{
	t_data	*cmd;
	int		i;
	
	i = 1;
	while (data)
	{
		while (data->next && data->next->token != ARG)
			data = data->next;
		if (!data || !data->next)
			return ;
		cmd = data;
		cmd->arg = malloc(sizeof(char *) * 255);
		cmd->arg[0] = ft_strdup(cmd->value);
		while (data->next && data->next->token == ARG)
		{
			cmd->arg[i] = ft_strdup(data->next->value);
			data = data->next;
			i++;
		}
		cmd->arg[i] = NULL;
		i = 1;
	}
}
