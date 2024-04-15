/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:58:32 by dpoltura          #+#    #+#             */
/*   Updated: 2024/04/15 12:42:30 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_parse.h"

void	init_env(t_data *data, char **envp)
{
	t_data	*cursor;
	int		i;

	cursor = data;
	i = 0;
	while (envp[i])
	{
		cursor->env = ft_split(envp[i], ':');
		if (envp[i + 1] && !cursor->next)
			init_data(&cursor->next);
		cursor = cursor->next;
		i++;
	}
}
