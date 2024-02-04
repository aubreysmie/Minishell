/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rangearraydup.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 14:02:04 by ekhaled           #+#    #+#             */
/*   Updated: 2024/02/04 14:02:14 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_range_array	ft_rangearraydup(t_range_array range_array)
{
	t_range_array	dup;
	int				i;

	dup.len = range_array.len;
	dup.array = malloc(dup.len * sizeof(t_range));
	i = 0;
	while (i < dup.len)
	{
		dup.array[i] = range_array.array[i];
		i++;
	}
	return (dup);
}
