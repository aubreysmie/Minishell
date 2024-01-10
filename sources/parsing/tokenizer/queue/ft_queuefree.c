/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queuefree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 21:28:36 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/10 23:21:18 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "parsing.h"

void	ft_queuefree(t_token_queue *queue)
{
	t_token_queue	*temp;

	if (!queue)
		return ;
	while (queue)
	{
		temp = queue;
		queue = queue->next;
		free(temp);
	}
}
