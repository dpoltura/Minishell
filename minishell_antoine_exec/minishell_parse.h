/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_parse.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduriez <aduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:05:05 by dpoltura          #+#    #+#             */
/*   Updated: 2024/06/10 12:08:38 by aduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_PARSE_H
# define MINISHELL_PARSE_H

# include "colors.h"
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>
#include <dirent.h>

typedef enum e_token
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
	INFILE,
	OUTFILE,
}					t_token;

typedef struct s_data
{
	int				index;
	char			*value;
	char			**arg;
	t_token			token;
	int				echo;
	char			*path;
	struct s_data	*prev;
	struct s_data	*next;

	// excve

}					t_data;

typedef struct s_excev
{
	// Conditions pour le infile
	int				open_file;
	// Conditions pour le outfile
	int				open_outfile;
	// Conditions pour les pipes
	int				fd[2];
	int				fd_origin[2];
	// Permet de determiner si la pipe est pleine
	int				pipe_filled;
	// Permet de gerer les cas d'erreur
	int				sup_directory;
	// Permet de voir si il y juste un infile une commande et un outile
	int				infile_nbr;
	int				cmd;
	int				save_fd_origin;
	int				save_fd;
}					t_excev;

void				init_data(t_data **data);
void				split_input(char *input, t_data *data);
void				free_data(t_data **data);
void				index_data(t_data *data);
void				token_data(t_data *data);
int					ft_strcmp(char *src, char *cmp);
char				*ft_strdup(const char *s);
void				arg_to_cmd(t_data *data);
size_t				ft_strlen(const char *s);
char				**ft_split(char const *s, char c);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
void				get_path(t_data *data);
void				free_split(char **split);
void				token_infile(t_data *data);
void				token_outfile(t_data *data);
void				ft_execve(t_data *data, char *envp[]);
void				ft_init_open_file(t_excev *base, t_data *data);
void				ft_next_infile(t_excev *base, t_data *data);
void				dump_pipe_to_terminal(int read_fd[], t_excev *base);
void				ft_fork_one(t_excev *base, char *envp[], t_data *data);
void				ft_display_envp(char *copy_envp[]);
char				**ft_display_envp_insert(t_data *data, char *copy_envp[]);

#endif
