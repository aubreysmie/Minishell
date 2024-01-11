/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queuelen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 22:39:03 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/11 22:43:06 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

unsigned int	ft_queuelen(t_token_queue *queue)
{
	unsigned int	i;

	i = 0;
	while (queue)
	{
		queue = queue->next;
		i++;
	}
	return (i);
}
