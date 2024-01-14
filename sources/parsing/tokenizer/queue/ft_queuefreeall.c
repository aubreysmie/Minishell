/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queuefreeall.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 05:34:48 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/14 05:36:59 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "parsing.h"

void	ft_queuefreeall(t_token_queue *queue)
{
	t_token_queue	*temp;

	if (!queue)
		return ;
	while (queue)
	{
		temp = queue;
		queue = queue->next;
		free(temp->token.content.str);
		free(temp);
	}
}
