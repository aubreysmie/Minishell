/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queuepop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 21:02:58 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/08 21:50:14 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "parsing.h"

t_token_queue	*ft_queuepop(t_token_queue **queue)
{
	t_token_queue	*element;

	if (!queue || !(*queue))
		return (NULL);
	element = *queue;
	*queue = (*queue)->next;
	return (element);
}
