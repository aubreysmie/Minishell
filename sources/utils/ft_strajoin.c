/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strajoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 22:13:47 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/09 22:28:35 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static unsigned int	get_joined_len(char **str_array)
{
	unsigned int	len;
	unsigned int	i;

	len = 0;
	i = 0;
	while (str_array[i])
	{
		len += ft_strlen(str_array[i]);
		i++;
	}
	return (len);
}

char	*ft_strajoin(char **str_array)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;
	char			*res;

	res = malloc((get_joined_len(str_array) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	k = 0;
	while (str_array[i])
	{
		j = 0;
		while (str_array[i][j])
		{
			res[k] = str_array[i][j];
			k++;
			j++;
		}
		i++;
	}
	res[k] = 0;
	return (res);
}
