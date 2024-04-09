/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 09:37:28 by dpoltura          #+#    #+#             */
/*   Updated: 2024/03/25 10:53:46 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**get_args(t_split *split_input, char **argv)
{
	t_split	*cursor;
	int	i;

	cursor = split_input;
	i = 1;
	while (cursor)
	{
		if (cursor->content[0] == '-')
		{
			argv[i] = ft_strdup(cursor->content);
			i++;
		}
		cursor = cursor->next;
	}
	argv[i] = NULL;
	return (argv);	
}
