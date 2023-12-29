/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stralen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 19:28:11 by ekhaled           #+#    #+#             */
/*   Updated: 2023/12/29 19:40:22 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stlib.h>

#include "utils.h"

int	ft_stralen(char **str_array)
{
	int	i;

	if (str_array == NULL)
		return (-1);
	i = 0;
	while (str_array[i])
		i++;
	return (i);
}
