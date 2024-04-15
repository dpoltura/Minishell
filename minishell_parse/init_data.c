/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:13:00 by dpoltura          #+#    #+#             */
/*   Updated: 2024/04/15 12:22:20 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_parse.h"

void	init_data(t_data **data)
{
	*data = malloc(sizeof(t_data));
	if (!(*data))
		exit(2);
    (*data)->index = 0;
	(*data)->value = NULL;
    (*data)->arg = NULL;
    (*data)->token = EMPTY;
	(*data)->path = NULL;
	(*data)->env = NULL;
    (*data)->next = NULL;
}
