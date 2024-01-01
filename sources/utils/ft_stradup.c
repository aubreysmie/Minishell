/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stradup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 17:18:05 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/01 17:30:47 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "utils.h"

static char	**ft_stradupfill(char **dup, char **str_array)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (str_array[i])
	{
		dup[i] = malloc((ft_strlen(str_array[i]) + 1) * sizeof(char));
		if (!dup[i])
		{
			ft_strafree(dup);
			return (NULL);
		}
		j = 0;
		while (str_array[i][j])
		{
			dup[i][j] = str_array[i][j];
			j++;
		}
		dup[i][j] = '\0';
		i++;
	}
	dup[i] = NULL;
	return (dup);
}

char	**ft_stradup(char **str_array)
{
	char			**dup;

	if (str_array == NULL)
		return (NULL);
	dup = malloc((ft_stralen(str_array) + 1) * sizeof(char *));
	if (!dup)
		return (NULL);
	return (ft_stradupfill(dup, str_array));
}
