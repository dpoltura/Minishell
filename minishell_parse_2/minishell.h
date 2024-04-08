/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:20:55 by dpoltura          #+#    #+#             */
/*   Updated: 2024/04/02 17:33:54 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <readline/history.h>
# include <readline/readline.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef enum e_token
{
	EMPTY,
	CMD,
	ARG,
	PIPE,
	CHEV,
}					t_token;

typedef struct s_input
{
	int				index;
	t_token			token;
	char			*value;
	struct s_input	*prev;
	struct s_input	*next;
}					t_input;

typedef struct s_data
{
	char			*line;
	t_input			*input;
}					t_data;

size_t				ft_strlen(const char *str);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strdup(const char *src);

#endif
