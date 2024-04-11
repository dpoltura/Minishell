/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_parse.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduriez <aduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:05:05 by dpoltura          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/04/11 16:51:38 by aduriez          ###   ########.fr       */
=======
<<<<<<< HEAD
/*   Updated: 2024/04/11 14:56:31 by dpoltura         ###   ########.fr       */
=======
/*   Updated: 2024/04/11 16:25:21 by dpoltura         ###   ########.fr       */
>>>>>>> Donovan
>>>>>>> refs/remotes/origin/main
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_PARSE_H
# define MINISHELL_PARSE_H

<<<<<<< HEAD
# include <fcntl.h>
=======
# include "colors.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <readline/readline.h>
>>>>>>> refs/remotes/origin/main
# include <readline/history.h>
# include <readline/readline.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
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
	char			*path;
	struct s_data	*prev;
	struct s_data	*next;

}					t_data;

typedef struct s_excev
{
	int				pipe_filled;
	int				open_outfile;
	int				open_file;
	int				fd[2];
	int				fd_origin[2];
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

#endif
