/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:50:29 by dpoltura          #+#    #+#             */
/*   Updated: 2024/04/10 16:49:42 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_parse.h"

static int		if_pipe(char *value)
{
	int		i;

	i = 0;
	while (value[i] == '|')
		i++;
	return (i);
}

static void	token_pipe(t_data *data)
{
	t_data	*cursor;
	
	cursor = data;
	while (cursor)
	{
		if (if_pipe(cursor->value) == 1)
			cursor->token = PIPE;
		else if (if_pipe(cursor->value) > 1)
		{
			free_data(&data);
			exit(2);
		}
		cursor = cursor->next;
	}
}

static int		if_l_chev(char *value)
{
	int		i;

	i = 0;
	while (value[i] == '<')
		i++;
	return (i);
}

static void	token_l_chev(t_data *data)
{
	t_data	*cursor;
	
	cursor = data;
	while (cursor)
	{
		if (if_l_chev(cursor->value) == 1)
			cursor->token = L_CHEV;
		else if (if_l_chev(cursor->value) == 2)
			cursor->token = D_L_CHEV;
		else if (if_l_chev(cursor->value) > 2)
		{
			free_data(&data);
			exit(2);
		}
		cursor = cursor->next;
	}
}

static int		if_r_chev(char *value)
{
	int		i;

	i = 0;
	while (value[i] == '>')
		i++;
	return (i);
}

static void	token_r_chev(t_data *data)
{
	t_data	*cursor;
	
	cursor = data;
	while (cursor)
	{
		if (if_r_chev(cursor->value) == 1)
			cursor->token = R_CHEV;
		else if (if_r_chev(cursor->value) == 2)
			cursor->token = D_R_CHEV;
		else if (if_r_chev(cursor->value) > 2)
		{
			free_data(&data);
			exit(2);
		}
		cursor = cursor->next;
	}
}

static int		if_s_quote(char *value)
{
	int		i;

	i = 0;
	while (value[i] == 39)
		i++;
	return (i);
}

static void	token_s_quote(t_data *data)
{
	t_data	*cursor;
	
	cursor = data;
	while (cursor)
	{
		if (if_s_quote(cursor->value) > 0)
			cursor->token = S_QUOTE;
		cursor = cursor->next;
	}
}

static int		if_d_quote(char *value)
{
	int		i;

	i = 0;
	while (value[i] == 34)
		i++;
	return (i);
}

static void	token_d_quote(t_data *data)
{
	t_data	*cursor;
	
	cursor = data;
	while (cursor)
	{
		if (if_d_quote(cursor->value) > 0)
			cursor->token = D_QUOTE;
		cursor = cursor->next;
	}
}

static int		if_dollar(char *value)
{
	int		i;

	i = 0;
	while (value[i] == '$')
		i++;
	return (i);
}

static void	token_dollar(t_data *data)
{
	t_data	*cursor;
	
	cursor = data;
	while (cursor)
	{
		if (if_dollar(cursor->value) > 0)
			cursor->token = DOLLAR;
		cursor = cursor->next;
	}
}

static int		if_arg(char *value)
{
	if (value[0] == '-')
		return (1);
	return (0);
}

static void	token_arg(t_data *data)
{
	t_data	*cursor;
	
	cursor = data;
	while (cursor)
	{
		if (if_arg(cursor->value))
			cursor->token = ARG;
		cursor = cursor->next;
	}
}

static void	token_echo(t_data *data)
{
	t_data	*cursor;
	
	cursor = data;
	while (cursor)
	{
		if (ft_strcmp(cursor->value, "echo"))
			cursor->token = ECHO;
		cursor = cursor->next;
	}
}

static void	token_cd(t_data *data)
{
	t_data	*cursor;
	
	cursor = data;
	while (cursor)
	{
		if (ft_strcmp(cursor->value, "cd"))
			cursor->token = CD;
		cursor = cursor->next;
	}
}

static void	token_pwd(t_data *data)
{
	t_data	*cursor;
	
	cursor = data;
	while (cursor)
	{
		if (ft_strcmp(cursor->value, "pwd"))
			cursor->token = PWD;
		cursor = cursor->next;
	}
}

static void	token_export(t_data *data)
{
	t_data	*cursor;
	
	cursor = data;
	while (cursor)
	{
		if (ft_strcmp(cursor->value, "export"))
			cursor->token = EXPORT;
		cursor = cursor->next;
	}
}

static void	token_unset(t_data *data)
{
	t_data	*cursor;
	
	cursor = data;
	while (cursor)
	{
		if (ft_strcmp(cursor->value, "unset"))
			cursor->token = UNSET;
		cursor = cursor->next;
	}
}

static void	token_env(t_data *data)
{
	t_data	*cursor;
	
	cursor = data;
	while (cursor)
	{
		if (ft_strcmp(cursor->value, "env"))
			cursor->token = ENV;
		cursor = cursor->next;
	}
}

static void	token_exit(t_data *data)
{
	t_data	*cursor;
	
	cursor = data;
	while (cursor)
	{
		if (ft_strcmp(cursor->value, "exit"))
			cursor->token = EXIT;
		cursor = cursor->next;
	}
}

static void	token_cmd(t_data *data)
{
	t_data	*cursor;
	
	cursor = data;
	while (cursor)
	{
		if (cursor->token == EMPTY)
			cursor->token = CMD;
		cursor = cursor->next;
	}
}

void	token_data(t_data *data)
{
	token_s_quote(data);
	token_d_quote(data);
	token_pipe(data);
	token_l_chev(data);
	token_r_chev(data);
	token_dollar(data);
	token_arg(data);
	token_echo(data);
	token_cd(data);
	token_pwd(data);
	token_export(data);
	token_unset(data);
	token_env(data);
	token_exit(data);
	token_cmd(data);
}
