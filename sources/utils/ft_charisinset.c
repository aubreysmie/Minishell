/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charisinset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:55:04 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/13 05:19:50 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

bool	ft_charisinset(char c, char set[])
{
	int	i;

	if (!set)
		return (0);
	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	if (c == set[i])
		return (1);
	return (0);
}
