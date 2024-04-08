/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:20:24 by dpoltura          #+#    #+#             */
/*   Updated: 2024/04/02 17:52:19 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*safe_malloc(int size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		exit(EXIT_FAILURE);
	return (ptr);
}

void	init(t_data *data)
{
	data = safe_malloc(sizeof(t_data));
	data->line = readline("minishell$ ");
	data->input = safe_malloc(sizeof(t_input));
	data->input->index = 0;
	data->input->token = EMPTY;
	data->input->value = NULL;
	data->input->prev = NULL;
	data->input->next = NULL;
}

void	split_input(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->line[i])
	{
		while (data->line[i] == ' ')
			i++;
		while (data->line[i] != '|' && data->line[i] != '<' && data->line[i] != '>')
		{
			data->input->value[j] = data->line[i];
			j++;
			i++;
		}
		while (data->line[i] == '|' || data->line[i] == '<' || data->line[i] == '>')
		{
			data->input->value[j] = data->line[i];
			j++;
			i++;
		}
	}
}

int	main(int argc, char **argv, char **env)
{
	(void) argc;
	(void) **argv;
	(void) **env;

	t_data	*data;
	init(data);
	
	return (0);
}
