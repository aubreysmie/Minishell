/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrcmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 04:52:57 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/04 05:24:22 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	ft_lstrcmp(t_lstr s1, t_lstr s2)
{
	unsigned int	i;

	i = 0;
	while (i < s1.len && i < s2.len)
	{
		if ((unsigned char)s1.str[i] != (unsigned char)s2.str[i])
			return ((unsigned char)s1.str[i] - (unsigned char)s2.str[i]);
		i++;
	}
	if (s1.len > s2.len)
		return ((unsigned char)s1.str[s2.len]);
	if (s1.len < s2.len)
		return (- ((unsigned char)s2.str[s1.len]));
	return (0);
}
