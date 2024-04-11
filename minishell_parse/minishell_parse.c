/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduriez <aduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:08:04 by dpoltura          #+#    #+#             */
/*   Updated: 2024/04/11 16:17:40 by aduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_parse.h"

static void	print_arg(t_data *data)
{
	int	i;

	i = 0;
	if (!data || !data->arg)
		return ;
	printf("[ ");
	while (data->arg[i])
	{
		printf("%s ", data->arg[i]);
		i++;
	}
	printf("]");
}

static char	*print_token(int token)
{
	char	*name;

	if (token == 0)
		name = strdup("EMPTY");
	if (token == 1)
		name = strdup("S_QUOTE");
	if (token == 2)
		name = strdup("D_QUOTE");
	if (token == 3)
		name = strdup("CMD");
	if (token == 4)
		name = strdup("PIPE");
	if (token == 5)
		name = strdup("L_CHEV");
	if (token == 6)
		name = strdup("R_CHEV");
	if (token == 7)
		name = strdup("D_L_CHEV");
	if (token == 8)
		name = strdup("D_R_CHEV");
	if (token == 9)
		name = strdup("DOLLAR");
	if (token == 10)
		name = strdup("ARG");
	if (token == 11)
		name = strdup("ECHO");
	if (token == 12)
		name = strdup("CD");
	if (token == 13)
		name = strdup("PWD");
	if (token == 14)
		name = strdup("EXPORT");
	if (token == 15)
		name = strdup("UNSET");
	if (token == 16)
		name = strdup("ENV");
	if (token == 17)
		name = strdup("EXIT");
	if (token == 18)
		name = strdup("INFILE");
	if (token == 19)
		name = strdup("OUTFILE");
	return (name);
}

static void	print_data(t_data *data)
{
	char	*token;
	int		i;

	i = 0;
	while (data)
	{
		token = print_token(data->token);
		printf("[ %d ][ %s ]", data->index, data->value);
		print_arg(data);
		printf("[ %s ]", token);
		printf("[ %s ]\n", data->path);
		data = data->next;
		free(token);
		i = 0;
	}
}

int	main(int arc, char *arg[], char *envp[])
{
	t_data	*data;
	char	*input;

	(void)arc;
	(void)arg;
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
		split_input(input, data);
		free(input);
		index_data(data);
		token_data(data);
		arg_to_cmd(data);
		get_path(data);
		token_infile(data);
		token_outfile(data);
		print_data(data);
		ft_execve(data, envp);
		free_data(&data);
	}
	return (0);
}
