/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:17:40 by dpoltura          #+#    #+#             */
/*   Updated: 2024/04/11 13:04:31 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_parse.h"

static void	free_arg(char **arg)
{
	int		i;

	i = 0;
	if (!arg)
		return ;
	while (arg[i])
	{
		free(arg[i]);
		i++;
	}
	free(arg);
}

void	free_data(t_data **data)
{
	t_data	*current;

	current = *data;
	while (current)
	{
		*data = (*data)->next;
		free(current->value);
		free_arg(current->arg);
		free(current);
		current = *data;
	}
}
