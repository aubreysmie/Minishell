/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 19:56:58 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/06 20:20:17 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "utils.h"

bool	ft_strarp(char **str_array, char *old_str, char *new_str)
{
	unsigned int	i;

	if (!str_array || !old_str || !new_str)
		return (0);
	i = 0;
	while (str_array[i])
	{
		if (str_array[i] == old_str)
		{
			str_array[i] = new_str;
			return (1);
		}
		i++;
	}
	return (1);
}
