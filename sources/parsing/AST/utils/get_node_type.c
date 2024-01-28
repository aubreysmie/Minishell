/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_node_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 06:17:10 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/23 06:17:21 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

enum e_node_type	get_node_type(enum e_token_type token_type)
{
	if (token_type == AND_IF_TOKEN)
		return (AND_IF_NODE);
	if (token_type == OR_IF_TOKEN)
		return (OR_IF_NODE);
	if (token_type == PIPE_TOKEN)
		return (PIPE_NODE);
	return (-1);
}
