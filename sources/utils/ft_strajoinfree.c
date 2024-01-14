/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strajoinfree.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:05:28 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/13 17:22:25 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_strajoinfree(char **str_array)
{
	unsigned int	i;
	char			*res;

	i = 0;
	res = ft_strajoin(str_array);
	if (!res)
		return (NULL);
	while (str_array[i])
	{
		free(str_array[i]);
		i++;
	}
	return (res);
}
