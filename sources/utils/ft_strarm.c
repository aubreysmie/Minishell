/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 22:07:56 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/05 14:07:31 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "utils.h"

bool	ft_strarm(char ***str_array_p, char *str)
{
	char			**new_str_array;
	unsigned int	i;
	unsigned int	offset;

	i = 0;
	offset = 0;
	if (!str_array_p || !str)
		return (0);
	new_str_array = malloc((ft_stralen(*str_array_p) * sizeof(char *)));
	if (!new_str_array)
		return (0);
	while ((*str_array_p)[i])
	{
		if ((*str_array_p)[i] == str)
			offset = 1;
		else
			new_str_array[i - offset] = (*str_array_p)[i];
		i++;
	}
	new_str_array[i - offset] = NULL;
	free(*str_array_p);
	*str_array_p = new_str_array;
	return (1);
}
