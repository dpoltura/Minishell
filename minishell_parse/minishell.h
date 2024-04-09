/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:20:55 by dpoltura          #+#    #+#             */
/*   Updated: 2024/04/09 12:43:58 by dpoltura         ###   ########.fr       */
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

typedef struct	s_split
{
	int		index;
	char	*content;
	struct s_split	*next;
}	t_split;

size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
void	split_line(t_split *split, char *line);
void	free_split(t_split *split);
char	*ft_strdup(const char *src);
void	*check_pipe(t_split *split, char *line);
void	index_split(t_split	*split);
int	count_split(t_split *split);
void	check_chev(t_split *split, char *line);
void	init_split(t_split **split);
int	ft_strcmp(char *src, char *cmp);
void	echo(t_split *split);

#endif
