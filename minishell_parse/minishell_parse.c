/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:08:04 by dpoltura          #+#    #+#             */
/*   Updated: 2024/04/10 17:29:44 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_parse.h"

static char	*print_token(int token)
{
	char	*name;

	if (token == 0)
		name = strdup("EMPTY");
	else if (token == 1)
		name = strdup("S_QUOTE");
	else if (token == 2)
		name = strdup("D_QUOTE");
    else if (token == 3)
		name = strdup("CMD");
    else if (token == 4)
		name = strdup("PIPE");
    else if (token == 5)
		name = strdup("L_CHEV");
    else if (token == 6)
		name = strdup("R_CHEV");
	else if (token == 7)
		name = strdup("D_L_CHEV");
    else if (token == 8)
		name = strdup("D_R_CHEV");
    else if (token == 9)
		name = strdup("DOLLAR");
	else if (token == 10)
		name = strdup("ARG");
    else if (token == 11)
		name = strdup("ECHO");
	else if (token == 12)
		name = strdup("CD");
	else if (token == 13)
		name = strdup("PWD");
    else if (token == 14)
		name = strdup("EXPORT");
    else if (token == 15)
		name = strdup("UNSET");
	else if (token == 16)
		name = strdup("ENV");
    if (token == 17)
		name = strdup("EXIT");
	return (name);
}

static void	print_data(t_data *data)
{
	char	*token;
	
	while (data)
	{
		token = print_token(data->token);
		printf("[ %d ][ %s ][ %s ]\n", data->index, data->value, token);
		data = data->next;
		free(token);
	}
}

int		main(void)
{
	t_data	*data;
	char	*input;

	data = NULL;
	while (1)
	{
		input = readline("minishell$ ");
		if (!input)
		{
			free(input);
			exit(2);
		}
		init_data(&data);
		split_input(input, data); // free
		free(input);
		index_data(data);
		token_data(data);
		
		print_data(data);
		free_data(&data);
	}
	return (0);
}
