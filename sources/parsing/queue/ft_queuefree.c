/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queuefree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 21:28:36 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/08 21:32:50 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "parsing.h"

void	ft_queuefree(t_token_queue *queue)
{
	t_token_queue	*temp;

	while (queue)
	{
		temp = queue;
		queue = queue->next;
		free(temp);
	}
}
