/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 23:34:22 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/22 04:14:48 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "parsing.h"

bool	init_node(t_node **node)
{
	*node = malloc(sizeof(t_node));
	if (!(*node))
		return (0);
	(*node)->type = -1;
	(*node)->parent = NULL;
	(*node)->left_child = NULL;
	(*node)->right_child = NULL;
	init_cmd(&(*node)->cmd);
	(*node)->was_printed = false;//debug
	return (1);
}