/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stradup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 17:18:05 by ekhaled           #+#    #+#             */
/*   Updated: 2023/12/29 20:16:11 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "utils.h"

char	**ft_stradup(char **str_array)
{
	char	**dup;
	uint	i;
	uint	j;

	if (str_array == NULL)
		return (NULL);
	i = 0;
	dup = malloc((ft_stralen(str_array) + 1) * sizeof(char *));
	while (str_array[i])
	{
		dup[i] = malloc((ft_strlen(str_array[i]) + 1) * sizeof(char));
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
