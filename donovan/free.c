/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:17:40 by dpoltura          #+#    #+#             */
/*   Updated: 2024/04/10 14:47:56 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_parse.h"

void	free_data(t_data **data)
{
	t_data	*current;

	current = *data;
	while (current)
	{
		*data = (*data)->next;
		free(current->value);
		free(current);
		current = *data;
	}
}
