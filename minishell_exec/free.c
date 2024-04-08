/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:31:07 by dpoltura          #+#    #+#             */
/*   Updated: 2024/03/25 10:15:13 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_split_input(t_data **data)
{
	char	*tmp_content;
	t_split	*tmp_next;

	while ((*data)->split_input)
	{
		tmp_content = (*data)->split_input->content;
		tmp_next = (*data)->split_input->next;
		free((*data)->split_input->content);
		free((*data)->split_input);
		(*data)->split_input = tmp_next;
	}
}

static void	free_env_vars(t_data **data)
{
	t_env	*tmp_env;
	t_split	*tmp_split;

	while ((*data)->env_vars)
	{
		while ((*data)->env_vars->var_split_content)
		{
			tmp_split = (*data)->env_vars->var_split_content->next;
			free((*data)->env_vars->var_split_content->content);
			free((*data)->env_vars->var_split_content);
			(*data)->env_vars->var_split_content = tmp_split;
		}
		tmp_env = (*data)->env_vars->next;
		free((*data)->env_vars);
		(*data)->env_vars = tmp_env;
	}
}

void	free_data(t_data **data)
{
	free((*data)->input);
	free_split_input(data);
	free_env_vars(data);
	free(*data);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	split = NULL;
}
