/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduriez <aduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 10:27:52 by dpoltura          #+#    #+#             */
/*   Updated: 2024/06/26 10:45:01 by aduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int    check_first(t_data *data)
{
    if (data->token == CMD && !data->path)
    {
        printf(ANSI_BOLDRED"%s: command not found\n"ANSI_RESET, data->value);
        free_data(&data);
        return (127);
    }
	else if ((data->token == PIPE || data->token == L_CHEV || data->token == R_CHEV
			|| data->token == D_L_CHEV || data->token == D_R_CHEV) && !data->next)
	{
		printf(ANSI_BOLDRED"minishell: syntax error `%s'\n"ANSI_RESET, data->value);
		free_data(&data);
        return (2);
	}
	return (1);
}
