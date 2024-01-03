/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_name.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 23:27:25 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/03 16:05:21 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "utils.h"
#include "parsing.h"

bool	is_name(char *name_candidate)
{
	int	i;

	if (!is_word(name_candidate))
		return (0);
	if (!(ft_isalpha(name_candidate[0]) || name_candidate[0] == '_'))
		return (0);
	i = 1;
	while (name_candidate[i])
	{
		if (!(ft_isalnum(name_candidate[i]) || name_candidate[i] == '_'))
			return (0);
		i++;
	}
	return (1);
}
