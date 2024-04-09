/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:56:51 by dpoltura          #+#    #+#             */
/*   Updated: 2024/03/21 14:56:45 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	split_env_var_content(t_data **data)
{
	t_split	*var_split_head;
	char	**split;
	int	i;
	
	var_split_head = (*data)->env_vars->var_split_content;
	split = ft_split((*data)->env_vars->var_content, ':');
	i = 0;
	while (split[i])
	{
		(*data)->env_vars->var_split_content->content = ft_strdup(split[i]);
		if (split[i + 1])
		{
			(*data)->env_vars->var_split_content->next = malloc(sizeof(t_split));
			(*data)->env_vars->var_split_content = (*data)->env_vars->var_split_content->next;
		}
		(*data)->env_vars->var_split_content->next = NULL;
		i++;
	}
	(*data)->env_vars->var_split_content = var_split_head;
	free_split(split);
}

static void	get_env_vars(char *var, t_data **data)
{
	t_env	*env_head;

	env_head = (*data)->env_vars;
	if ((*data)->env_vars->var)
	{
		while ((*data)->env_vars->next)
			(*data)->env_vars = (*data)->env_vars->next;
		(*data)->env_vars->next = malloc(sizeof(t_env));
		(*data)->env_vars = (*data)->env_vars->next;
		(*data)->env_vars->var_split_content = malloc(sizeof(t_split));
	}
	(*data)->env_vars->var = ft_strdup(var);
	(*data)->env_vars->var_content = getenv(var);
	split_env_var_content(data);
	(*data)->env_vars->next = NULL;
	(*data)->env_vars = env_head;
}

void	ft_getenv(t_data **data)
{
	get_env_vars("USER", data);
	get_env_vars("HOME", data);
	get_env_vars("PATH", data);
	get_env_vars("PWD", data);
	get_env_vars("OLDPWD", data);
}
