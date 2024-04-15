/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 10:40:56 by dpoltura          #+#    #+#             */
/*   Updated: 2024/04/15 10:46:31 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_parse.h"

char	*ft_readline(void)
{
	char	*input;
	
	printf(ANSI_BOLDWHITE ANSI_BLACK_BACKGROUND" 💀 MINISHELL "ANSI_RESET);
    printf(ANSI_BLACK""ANSI_RESET);
	input = readline(" ");
	return (input);
}
