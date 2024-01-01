/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stralen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 19:28:11 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/01 18:46:51 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_stralen(char **str_array)
{
	unsigned int	i;

	if (str_array == NULL)
		return (-1);
	i = 0;
	while (str_array[i])
		i++;
	return (i);
}
