/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:21:42 by dpoltura          #+#    #+#             */
/*   Updated: 2024/04/10 16:43:23 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_parse.h"

int		ft_strcmp(char *src, char *cmp)
{
	int		i;

	i = 0;
	while (src[i] && cmp[i] && src[i] == cmp[i])
		i++;
	if (!src[i] && !cmp[i])
		return (1);
	return (0);
}

void	index_data(t_data *data)
{
	int		i;

	i = 1;
	while (data)
	{
		data->index = i;
		data = data->next;
		i++;		
	}
}
