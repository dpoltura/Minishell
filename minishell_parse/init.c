/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 10:44:34 by dpoltura          #+#    #+#             */
/*   Updated: 2024/04/09 10:47:17 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_split(t_split **split)
{
	*split = malloc(sizeof(t_split));
	(*split)->index = 0;
	(*split)->content = NULL;
	(*split)->next = NULL;
}
