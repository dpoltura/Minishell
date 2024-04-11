/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_parse.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:05:05 by dpoltura          #+#    #+#             */
/*   Updated: 2024/04/11 13:04:38 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_PARSE_H
# define MINISHELL_PARSE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef enum	e_token
{
    EMPTY,
	S_QUOTE,
	D_QUOTE,
    CMD,
    PIPE,
    L_CHEV,
    R_CHEV,
    D_L_CHEV,
    D_R_CHEV,
    DOLLAR,
    ARG,
    ECHO,
    CD,
    PWD,
    EXPORT,
    UNSET,
    ENV,
    EXIT,
}	t_token;

typedef struct	s_data
{
    int		index;
    char	*value;
    char	**arg;
    t_token	token;
    char    *path;
    struct s_data	*prev;
    struct s_data	*next;
}	t_data;

void	init_data(t_data **data);
void	split_input(char *input, t_data *data);
void	free_data(t_data **data);
void	index_data(t_data *data);
void	token_data(t_data *data);
int		ft_strcmp(char *src, char *cmp);
char    *ft_strdup(const char *s);
void	arg_to_cmd(t_data *data);
size_t  ft_strlen(const char *s);

#endif
