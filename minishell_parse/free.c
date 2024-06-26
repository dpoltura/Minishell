/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:17:40 by dpoltura          #+#    #+#             */
/*   Updated: 2024/04/15 14:09:18 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_parse.h"

void	free_split(char **split)
{
	int		i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	free_env(t_env **env)
{
	t_env	*current;

	current = *env;
	while (current)
	{
		*env = (*env)->next;
		free(current->key);
		free_split(current->value);
		free(current);
		current = *env;
	}
}

void	free_data(t_data **data)
{
	t_data	*current;

	current = *data;
	while (current)
	{
		*data = (*data)->next;
		free(current->value);
		free_split(current->arg);
		free(current->path);
		free(current);
		current = *data;
	}
}
