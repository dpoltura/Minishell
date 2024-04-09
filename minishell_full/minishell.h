/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:20:55 by dpoltura          #+#    #+#             */
/*   Updated: 2024/04/09 13:25:31 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "colors.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct	s_split
{
	int		index;
	char	*content;
	struct s_split	*next;
}	t_split;

typedef struct s_env
{
	char			*var;
	char			*var_content;
	t_split			*var_split_content;
	struct s_env	*next;
}					t_env;

typedef struct s_data
{
	char			*input;
	t_split			*split_input;
	t_env			*env_vars;
	pid_t			pid;
}					t_data;

size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
void	split_line(t_split *split, char *line);
void	free_split(char **split);
char	*ft_strdup(const char *src);
void	*check_pipe(t_data **data);
void	index_split(t_data **data);
int	count_split(t_data **data);
void	check_chev(t_data **data);
void	init_split(t_split **split);
int	ft_strcmp(char *src, char *cmp);
void	echo(t_data **data);
t_env	*get_var(char *var, t_data **data);
char	**get_args(t_split *split_input, char **argv);
char	**ft_split(char const *s, char c);
void	ft_readline(t_data **data);
void	init_data(t_data **data);
void	split_input(t_data **data);
void	free_data(t_data **data);
void	ft_getenv(t_data **data);
void	ft_execve(t_data **data, char **argv, char **env);

#endif
