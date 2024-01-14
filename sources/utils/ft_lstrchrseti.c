/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrchrseti.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 23:47:20 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/13 01:49:40 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "parsing.h"

int	ft_lstrchrseti(t_lstr lstr, char set[])
{
	unsigned int	i;

	i = 0;
	while (i < lstr.len)
	{
		if (ft_charisinset(lstr.str[i], set))
			return (i);
		i++;
	}
	return (-1);
}
