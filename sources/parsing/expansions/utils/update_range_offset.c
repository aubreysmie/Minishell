/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_range_offset.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 10:24:29 by ekhaled           #+#    #+#             */
/*   Updated: 2024/02/04 16:05:09 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	update_range_offset(t_range_array *range_array, int offset)
{
	static int	i;
	int			j;

	if (range_array->len == 0)
		return ;
	if (i == range_array->len - 1)
	{
		range_array->array[i].end -= offset;
		i = 0;
		return ;
	}
	while (range_array->array[i].is_quoted)
		i++;
	range_array->array[i].end -= offset;
	j = i + 1;
	while (j < range_array->len)
	{
		range_array->array[j].start -= offset;
		range_array->array[j].end -= offset;
		j++;
	}
}
