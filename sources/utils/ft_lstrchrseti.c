/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrchrseti.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 23:47:20 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/12 23:49:37 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "parsing.h"

int	ft_lstrchrseti(t_lstr lstr, char set[])
{
	int	i;

	i = 0;
	while (i < lstr.len)
	{
		if (ft_charisin(lstr.str[i], set))
			return (i);
		i++;
	}
}
