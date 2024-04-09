/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 09:52:15 by dpoltura          #+#    #+#             */
/*   Updated: 2024/04/09 12:11:47 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// ============= LIBRAIRIES =============

# include "colors.h"
# include <readline/readline.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>

// ============= STRUCT & LIST =============

typedef struct s_split
{
	char			*content;
	struct s_split	*next;
}					t_split;

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

// ============= FUNCTIONS =============

void				init_data(t_data **data);
void				free_data(t_data **data);
char				**ft_split(char const *s, char c);
void	split_input(t_data **data);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *src);
void	ft_getenv(t_data **data);
int	ft_strcmp(char *s1, char *s2);
void	free_split(char **split);
void	ft_readline(t_data **data);
t_env	*get_var(char *var, t_data **data);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_execve(t_data **data, char **argv, char **env);
char	**get_args(t_split *split_input, char **argv);

// ============= TESTS FUNCTIONS =============

void	print_input(t_data **data);
void	print_env_split_var(t_data **data);

#endif
