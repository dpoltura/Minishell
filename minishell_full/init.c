/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:29:17 by dpoltura          #+#    #+#             */
/*   Updated: 2024/04/09 12:39:05 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	init_split_input(t_data **data)
{
	(*data)->split_input = malloc(sizeof(t_split));
	(*data)->split_input->index = 0;
	(*data)->split_input->content = NULL;
	(*data)->split_input->next = NULL;
}

static void	init_env_vars(t_data **data)
{
	(*data)->env_vars = malloc(sizeof(t_env));
	(*data)->env_vars->var = NULL;
	(*data)->env_vars->var_content = NULL;
	(*data)->env_vars->var_split_content = malloc(sizeof(t_split));
	(*data)->env_vars->var_split_content->content = NULL;
	(*data)->env_vars->var_split_content->next = NULL;
	(*data)->env_vars->next = NULL;
}

void	init_data(t_data **data)
{
	*data = malloc(sizeof(t_data));
	(*data)->input = NULL;
	init_split_input(data);
	init_env_vars(data);
	(*data)->pid = 0;
}
