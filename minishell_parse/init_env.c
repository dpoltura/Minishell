/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:58:32 by dpoltura          #+#    #+#             */
/*   Updated: 2024/04/15 13:17:32 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_parse.h"

void	init_env(t_data *data, char **envp)
{
	t_data	*cursor;
	char	**tmp;
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
	cursor = data;
	while (cursor && cursor->env)
	{
		tmp = ft_split(cursor->env[0], '=');
		cursor->var = ft_strdup(tmp[0]);
		free(cursor->env[0]);
		cursor->env[0] = NULL;
		cursor->env[0] = ft_strdup(tmp[1]);
		free_split(tmp);
		cursor = cursor->next;
	}
}
