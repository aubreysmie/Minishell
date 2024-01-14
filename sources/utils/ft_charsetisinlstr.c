/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charsetisinlstr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 23:58:08 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/13 01:49:09 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "parsing.h"
#include "utils.h"

bool	ft_charsetisinlstr(char set[], t_lstr lstr)
{
	unsigned int	i;

	i = 0;
	while (i < lstr.len)
	{
		if (ft_charisinset(lstr.str[i], set))
			return (true);
		i++;
	}
	return (false);
}
