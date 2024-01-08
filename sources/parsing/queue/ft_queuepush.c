/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queuepush.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 20:53:04 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/08 21:44:35 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "parsing.h"

void	ft_queuepush(t_token_queue **queue, t_token_queue *new)
{
	if (!queue || !new)
		return ;
	if (!(*queue))
	{
		*queue = new;
		return ;
	}
	ft_queuelast(*queue)->next = new;
	return ;
}
