/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_straadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 01:48:00 by ekhaled           #+#    #+#             */
/*   Updated: 2023/12/30 02:57:05 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

#include "utils.h"

bool	ft_straaddnull(char ***str_array_p, char *new_str)
{
	char				**new_str_array;

	new_str_array = malloc(2 * sizeof(char *));
	if (!new_str_array)
		return (0);
	new_str_array[0] = new_str;
	new_str_array[1] = NULL;
	*str_array_p = new_str_array;
	return (1);
}

bool	ft_straadd(char ***str_array_p, char *new_str)
{
	char				**new_str_array;
	unsigned int		i;

	i = 0;
	if (!(*str_array_p))
		return (ft_straaddnull(str_array_p, new_str));
	new_str_array = malloc((ft_stralen(*str_array_p) + 2) * sizeof(char *));
	if (!new_str_array)
		return (0);
	while ((*str_array_p)[i])
	{
		new_str_array[i] = (*str_array_p)[i];
		i++;
	}
	new_str_array[i] = new_str;
	new_str_array[i + 1] = NULL;
	free(*str_array_p);
	*str_array_p = new_str_array;
	return (1);
}
