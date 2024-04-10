/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:13:00 by dpoltura          #+#    #+#             */
/*   Updated: 2024/04/10 14:44:59 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_parse.h"

void	init_data(t_data **data)
{
	*data = malloc(sizeof(t_data));
	if (!(*data))
		exit(2);
    (*data)->index = 0;
	(*data)->value = malloc(sizeof(char) * 255);
	if (!(*data)->value)
		exit(2);
    (*data)->arg = NULL;
    (*data)->token = EMPTY;
    (*data)->prev = NULL;
    (*data)->next = NULL;
}
