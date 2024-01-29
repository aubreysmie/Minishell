/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisinstra.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 20:28:37 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/27 20:31:01 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

bool	ft_strisinstra(char *str, char **str_array)
{
	int	i;

	i = 0;
	if (!str)
		return (true);
	while (str_array[i])
	{
		if (ft_strareeq(str, str_array[i]))
			return (true);
		i++;
	}
	return (false);
}
