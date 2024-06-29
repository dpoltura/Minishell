/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduriez <aduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:05:05 by dpoltura          #+#    #+#             */
/*   Updated: 2024/06/28 17:07:21 by aduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_PARSE_H
# define MINISHELL_PARSE_H

# include "colors.h"
# include <dirent.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <termios.h>
# include <unistd.h>

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
	ECHO_CMD,
	ECHO_N,
	NNN_ECHO,
	ECHO_ARG,
	CD,
	PWD,
	EXPORT,
	UNSET,
	ENV,
	EXIT,
	INFILE,
	OUTFILE,
	HERE_DOC,
	END_HERE_DOC,
}					t_token;

typedef struct s_env
{
	char			*key;
	char			**value;
	struct s_env	*next;
}					t_env;

typedef struct s_data
{
	int				index;
	char			*value;
	char			**arg;
	t_token			token;
	char			*path;
	struct s_data	*next;
	struct s_data	*prev;
	int				status;
	int				outfile;

}					t_data;

typedef struct s_excev
{
	// Conditions pour le infile
	int				open_file;
	int				infile_nbr;
	// Conditions pour le outfile
	int				iterateur_outfile;
	int				open_outfile;
	int				nbr_outfile;
	// Conditions pour les pipes
	int				fd[2];
	int				fd_origin[2];
	// Permet de determiner si la pipe est pleine
	int				pipe_filled;
	// Permet de gerer les cas d'erreur
	int				sup_directory;
	// Permet de voir si il y juste un infile une commande et un outile
	int				cmd;
	int				save_fd_origin;
	int				save_fd;
	// Pour ce putain de controle d
	pthread_mutex_t	here;
	// Nouvelle conditions pour les pipes
	int				all_pipe[1023][2];
	int				init_pipe;
	// Nouvelle conditions pour les fd
	// int				fd[1023];
	int				init_fd;
	int				nbr_pipe;
	int				*data_exit;

}					t_excev;

void				ft_verfife_outifile(t_data *data);
void 				init_data(t_data **data);
void				split_input(char *input, t_data *data);
void				free_data(t_data **data);
void				index_data(t_data *data);
int					token_data(t_data *data);
int					ft_strcmp(char *src, char *cmp);
char				*ft_strdup(const char *s);
void				arg_to_cmd(t_data *data);
int				ft_strlen(const char *s);
char				**ft_split(char const *s, char c);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
void				get_path(t_data *data);
void				free_split(char **split);
void				token_infile(t_data *data);
void				token_outfile(t_data *data);
int					check_first(t_data *data);
char				*ft_readline(t_env *env);
void				env_copy(t_env *env, char **envp);
void				free_env(t_env **env);
void				init_env(t_env **env);
char				**ft_execve(t_data *data, char **envp);
void				ft_echo(t_data *data);
int					count_quotes(char *input);
char				*remove_quotes(char *input);
void				token_here_doc(t_data *data);
void				ft_here_doc(char *value, t_data *data, char *envp[]);
void				ft_init_signaux(struct sigaction *action,
						char **write_here_do);
void				ft_manager_sig(int sig);
void				ft_here_doc_init(t_data **data);
void				shell_loop(t_data **data, char **envp);
void				ft_display_envp(char *copy_envp[]);
char				**ft_display_envp_insert(t_data *data, char *copy_envp[]);

#endif
