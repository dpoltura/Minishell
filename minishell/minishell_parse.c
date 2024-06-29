/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduriez <aduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:08:04 by dpoltura          #+#    #+#             */
/*   Updated: 2024/06/29 17:24:46 by aduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_arg(t_data *data)
{
	int	i;

	i = 0;
	if (!data || !data->arg)
		return ;
	printf(ANSI_BLUE "char " ANSI_RED "**" ANSI_CYAN "arg " ANSI_RED "= " ANSI_WHITE);
	while (data->arg[i])
	{
		printf("%s", data->arg[i]);
		i++;
		if (data->arg[i])
			printf(", ");
		else
			printf(";");
	}
	printf("\n\t");
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
	if (token == 20)
		name = strdup("HERE_DOC");
	if (token == 21)
		name = strdup("END_HERE_DOC");
	return (name);
}

static void	print_data(t_data *data)
{
	int	i;

	i = 0;
	while (data)
	{
		print_token(data->token);
		printf(ANSI_RED "\ntypedef " ANSI_BLUE "struct\t" ANSI_GREEN "s_data\n");
		printf(ANSI_YELLOW "{");
		printf("\n\t" ANSI_BLUE "int " ANSI_CYAN "index " ANSI_RED "= " ANSI_WHITE "%d;\n\t",
			data->index);
		printf(ANSI_BLUE "char " ANSI_RED "*" ANSI_CYAN "value " ANSI_RED "= " ANSI_WHITE "%s;\n\t",
			data->value);
		print_arg(data);
		printf(ANSI_GREEN "t_token " ANSI_CYAN "token " ANSI_RED "= " ANSI_WHITE "%u;\n\t",
			data->token);
		printf(ANSI_BLUE "char " ANSI_RED "*" ANSI_CYAN "path " ANSI_RED "= " ANSI_WHITE "%s;\n",
			data->path);
		printf(ANSI_RED "\n%d\n" ANSI_WHITE, data->outfile);
		printf(ANSI_YELLOW "}\n" ANSI_WHITE);
		data = data->next;
		if (!data)
			printf("\n");
		i = 0;
	}
}
void	verif_token(t_data *data)
{
	printf("|data->value|%s|", data->value);
	if (ft_strcmp(data->value, "echo"))
		data->token = CD;
	printf("|data->token|%u|", data->token);
}
void	shell_loop(t_data **data, char **env)
{
	char	*input;
	char	*safe_input;
	char	**tmp_env;

	tmp_env = env;
	(void)env;
	while (1)
	{
		input = readline("minishell$ ");
		if (!input)
		{
			free(input);
			printf("exit\n");
			exit(2);
		}
		// add_history(input);
		safe_input = remove_quotes(input);
		if (!safe_input)
			break ;
		init_data(data);
		split_input(safe_input, *data);
		free(safe_input);
		index_data(*data);
		if (token_data(*data) != 1)
			break ;
		printf("\nQQQQ\n");
		verif_token(*data);
		get_path(*data);
		token_infile(*data);
		token_outfile(*data);
		token_here_doc(*data);
		arg_to_cmd(*data);
		ft_verfife_outifile(*data);
		if (check_first(*data) != 1)
			break ;
		print_data(*data);
		if (strcmp((*data)->value, "env") == 0)
		{
			if ((*data)->arg != NULL)
			{
				printf("\n1|conditions|\n");
				if (strcmp((*data)->arg[1], "-n") == 0)
					tmp_env = ft_display_envp_insert(*data, tmp_env);
			}

			else
				ft_display_envp(tmp_env);
		}
		// else
		// {
			// ft_execve(*data, tmp_env);
		// }
		free_data(data);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_env	*env;
	char	**env_tab;
	t_data	*data;

	(void)argc;
	argv = NULL;
	// int i = 0;
	env = NULL;
	// init_env(&env);
	env_tab = envp;
	data = NULL;
	shell_loop(&data, env_tab);
	return (0);
}
