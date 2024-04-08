/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:41:31 by dpoltura          #+#    #+#             */
/*   Updated: 2024/03/21 10:53:34 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	split_input(t_data **data)
{
	char	**split;
	t_split *cursor;
	int	i;

	split = ft_split((*data)->input, ' ');
	cursor = (*data)->split_input;
	i = 0;
	while (split[i])
	{
		cursor->content = ft_strdup(split[i]);
		if (split[i + 1])
		{
			cursor->next = malloc(sizeof(t_split));
			cursor = cursor->next;
		}
		cursor->next = NULL;
		i++;
	}
	free_split(split);
}
