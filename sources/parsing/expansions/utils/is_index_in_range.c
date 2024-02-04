/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_index_in_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 16:50:58 by ekhaled           #+#    #+#             */
/*   Updated: 2024/02/03 16:51:30 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_index_in_range(int index, t_range_array *range_array,
			bool *is_quoted)
{
	int	i;

	i = 0;
	while (i < range_array->len)
	{
		if (range_array->array[i].start <= index
			&& index < range_array->array[i].end)
		{
			if (is_quoted)
				*is_quoted = range_array->array[i].is_quoted;
			return (true);
		}
		i++;
	}
	return (false);
}
