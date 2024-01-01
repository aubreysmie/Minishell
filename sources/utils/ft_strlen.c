/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 19:56:24 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/01 16:52:22 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "utils.h"

int	ft_strlen(const char *str)
{
	unsigned int	i;

	i = 0;
	if (str == NULL)
		return (-1);
	while (str[i])
		i++;
	return (i);
}
