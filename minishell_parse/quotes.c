/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:15:30 by dpoltura          #+#    #+#             */
/*   Updated: 2024/06/10 15:35:56 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_parse.h"

int     count_quotes(char *input)
{
        int     i;
        int     count;

        i = 0;
        count = 0;
        while (input[i])
        {
                if (input[i] == 34 || input[i] == 39)
                        count++;
                i++;
        }
        return (count);
}

char    *remove_quotes(char *input)
{
        int     i;
        int     j;
        char    *cpy;
        
        i = 0;
        j = 0;
        cpy = malloc(sizeof(char) * 255);
        while (input[i])
        {
                if (input[i] != 34 && input[i] != 39)
                {
                        cpy[j] = input[i];
                        j++;
                }
                i++;
        }
        cpy[j] = '\0';
        free(input);
        return (cpy);
}
