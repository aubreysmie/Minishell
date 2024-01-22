/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pipe_parent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 01:30:37 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/22 04:05:27 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	create_pipe_parent(t_cstr *input, t_token_queue **token_queue,
			t_token_queue **heredoc_queue, t_node **node)
{
	t_node	*new_node;

	free(ft_queuepop(token_queue));
	skip_newlines(token_queue);
	while (!(*token_queue))
		if (!update_token_queue(input, token_queue, heredoc_queue))
			return (0);
	if (!init_node(&new_node))
		return (0);
	new_node->type = PIPE_NODE;
	new_node->left_child = *node;
	(*node)->parent = new_node;
	*node = new_node;
	if (!create_leaf(input, token_queue, heredoc_queue,
			&new_node->right_child))
		return (free_ast(new_node), 0);
	if (has_wrong_synthax(node, new_node->right_child))
		return (1);
	new_node->right_child->parent = new_node;
	if ((*token_queue) && (*token_queue)->token.type == PIPE_TOKEN)
		return (create_pipe_parent(input, token_queue, heredoc_queue, node));
	return (1);
}
