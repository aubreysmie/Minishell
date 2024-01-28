/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_child.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 05:38:28 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/27 06:36:31 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	create_child(t_cstr *input, t_token_queue **token_queue,
			t_token_queue **heredoc_queue, t_node **left_child)
{
	if ((*token_queue) && (*token_queue)->token.type == LPAR_TOKEN)
	{
		if (!create_sub_prioritree(input, token_queue,
				heredoc_queue, left_child))
			return (0);
	}
	else
	{
		if (!create_pipe_sub_tree(input, token_queue,
				heredoc_queue, left_child))
			return (0);
	}
	return (1);
}
