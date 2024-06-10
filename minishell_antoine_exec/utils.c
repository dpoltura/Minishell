/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduriez <aduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:21:42 by dpoltura          #+#    #+#             */
/*   Updated: 2024/06/05 14:43:32 by aduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_parse.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_strcmp(char *src, char *cmp)
{
	int	i;

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
	t_data	*prev;
	prev=NULL;

	i = 1;
	while (data)
	{
		data->prev = prev; // mettre à jour le champ prev de l'élément actuel
		prev = data;
		// mettre à jour la variable prev pour l'itération suivante
		data->index = i;
		data = data->next;
		i++;
	}
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*str;

	i = 0;
	str = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (str == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
