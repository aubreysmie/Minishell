/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrseti.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:22:12 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/12 18:32:18 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_strchrseti(const char *str, char set[])
{
	int	i;

	if (!str || !set)
		return (-2);
	i = 0;
	while (str[i])
	{
		if (ft_charisin(str[i], set))
			return (i);
		i++;
	}
	if (ft_charisin(str[i], set))
		return (i);
	return (-1);
}
