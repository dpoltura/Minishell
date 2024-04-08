/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 12:52:09 by dpoltura          #+#    #+#             */
/*   Updated: 2024/03/28 13:02:16 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_split(t_split *split)
{
	t_split	*tmp;

	while (split)
	{
		tmp = split;
		split = split->next;
		free(tmp->content);
		free(tmp);
	}
	free(split);
}
