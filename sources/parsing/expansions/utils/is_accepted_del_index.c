/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_accepted_del_index.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 10:23:41 by ekhaled           #+#    #+#             */
/*   Updated: 2024/02/02 10:23:59 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_accepted_del_index(int index_candidate, t_range_array range_array)
{
	int	i;

	i = 0;
	while (i < range_array.len)
	{
		if (range_array.array[i].is_quoted == false
			&& range_array.array[i].start <= index_candidate
			&& index_candidate < range_array.array[i].end)
			return (true);
		i++;
	}
	return (false);
}
