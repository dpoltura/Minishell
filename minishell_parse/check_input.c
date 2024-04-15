/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 10:27:52 by dpoltura          #+#    #+#             */
/*   Updated: 2024/04/15 10:39:01 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_parse.h"

void    check_first(t_data *data)
{
        if (data->token == CMD && !data->path)
        {
                printf(ANSI_BOLDRED"%s: command not found\n"ANSI_RESET, data->value);
                free_data(&data);
                exit(127);
        }
		else if (data->token != CMD && !data->next)
		{
			printf(ANSI_BOLDRED"minishell: syntax error `%s'\n"ANSI_RESET, data->value);
			free_data(&data);
            exit(2);
		}
}
