/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:17:00 by dpoltura          #+#    #+#             */
/*   Updated: 2024/04/09 13:17:19 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_echo_arg(char *src, char *cmp)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (src[i] && cmp[j] && src[i] == cmp[j])
	{
		i++;
		j++;
	}
	if (!cmp[j])
	{
		while (src[i] == 'n')
			i++;
		if (!src[i])
			return (1);
	}
	return (0);
}

void	echo(t_data **data)
{
	t_split	*cursor;
	int	i;
	char	c[1];

	cursor = (*data)->split_input;
	c[0] = '\n';
	while (cursor && !ft_strcmp(cursor->content, "echo"))
		cursor = cursor->next;
	if (!cursor)
		return ;
	else if (cursor)
		cursor = cursor->next;
	if (cursor && ft_echo_arg(cursor->content, "-n"))
	{
		c[0] = 0;
		cursor = cursor->next;
	}
	i = 0;
	while (cursor && cursor->content[i])
	{
		write(1, &cursor->content[i], 1);
		i++;
	}
	write(1, &c[0], 1);
}
