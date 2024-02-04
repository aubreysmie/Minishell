/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rangeaadd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:23:40 by ekhaled           #+#    #+#             */
/*   Updated: 2024/02/02 08:59:25 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	ft_rangeaaddnull(t_range_array *range_array, t_range new_range)
{
	t_range	*new_range_array;

	new_range_array = malloc(1 * sizeof(t_range));
	if (!new_range_array)
		return (0);
	new_range_array[0] = new_range;
	range_array->array = new_range_array;
	range_array->len = 1;
	return (1);
}

bool	ft_rangeaadd(t_range_array *range_array, t_range new_range)
{
	t_range	*new_range_array;
	int		i;

	i = 0;
	if (!range_array)
		return (0);
	if (range_array->len == 0)
		return (ft_rangeaaddnull(range_array, new_range));
	new_range_array = malloc((range_array->len + 1) * sizeof(t_range));
	if (!new_range_array)
		return (0);
	while (i < range_array->len)
	{
		new_range_array[i] = range_array->array[i];
		i++;
	}
	new_range_array[i] = new_range;
	(range_array->len)++;
	free(range_array->array);
	range_array->array = new_range_array;
	return (1);
}
