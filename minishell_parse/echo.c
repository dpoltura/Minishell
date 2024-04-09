/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:17:00 by dpoltura          #+#    #+#             */
/*   Updated: 2024/04/09 11:55:55 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	echo(t_split *split)
{
	t_split	*cursor;
	int	i;
	char	c[1];

	cursor = split;
	c[0] = '\n';
	while (cursor && !ft_strcmp(cursor->content, "echo"))
		cursor = cursor->next;
	if (!cursor)
		return ;
	else if (cursor)
		cursor = cursor->next;
	if (cursor && ft_strcmp(cursor->content, "-n"))
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
