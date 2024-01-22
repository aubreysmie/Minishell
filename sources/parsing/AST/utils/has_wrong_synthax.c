/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_wrong_synthax.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 01:52:59 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/22 01:53:18 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	has_wrong_synthax(t_node **node, t_node *child)
{
	if (!child)
	{
		free_ast(*node);
		*node = NULL;
		return (1);
	}
	return (0);
}
