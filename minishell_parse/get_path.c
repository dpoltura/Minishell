/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:26:05 by dpoltura          #+#    #+#             */
/*   Updated: 2024/04/15 17:41:34 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_parse.h"

void	get_path(t_data *data)
{
	char	*path;
	char	**split_path;
	char	*full_path;
	int		i;

	path = getenv("PATH");
	split_path = ft_split(path, ':');
	i = 0;
	while (data)
	{
		while (data && data->token == CMD && split_path[i])
		{
			full_path = ft_strjoin(split_path[i], "/");
			data->path = ft_strjoin(full_path, data->value);
			free(full_path);
			if (access(data->path, F_OK | X_OK) != -1)
			{
				data = data->next;
				i = 0;
			}
			else
			{
				free(data->path);
				data->path = NULL;
				i++;
			}
		}
		if (data)
			data = data->next;
		i = 0;
	}
	free_split(split_path);
}
