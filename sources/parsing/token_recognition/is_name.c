/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_name.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 23:27:25 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/03 19:26:16 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "utils.h"
#include "parsing.h"

bool	is_name(t_lstr name_candidate)
{
	int	i;

	if (!is_word(name_candidate))
		return (0);
	if (!(ft_isalpha(name_candidate.str[0]) || name_candidate.str[0] == '_'))
		return (0);
	i = 1;
	while (i < name_candidate.len)
	{
		if (!(ft_isalnum(name_candidate.str[i])
				|| name_candidate.str[i] == '_'))
			return (0);
		i++;
	}
	return (1);
}
