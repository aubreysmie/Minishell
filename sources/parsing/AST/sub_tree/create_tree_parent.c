/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tree_parent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 05:24:43 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/27 06:36:10 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	create_tree_parent(t_cstr *input, t_token_queue **token_queue,
			t_token_queue **heredoc_queue, t_node **node)
{
	t_node		*new_node;

	if (!init_node(&new_node))
		return (0);
	new_node->type = get_node_type((*token_queue)->token.type);
	free(ft_queuepop(token_queue));
	if (!get_token_other_than_newline(input, token_queue, heredoc_queue))
		return (free(new_node), 0);
	new_node->left_child = *node;
	(*node)->parent = new_node;
	*node = new_node;
	if (!create_child(input, token_queue, heredoc_queue,
			&new_node->right_child))
		return (free_ast(new_node), 0);
	if (has_wrong_synthax(node, new_node->right_child))
		return (1);
	new_node->right_child->parent = new_node;
	if ((*token_queue) && ((*token_queue)->token.type == AND_IF_TOKEN
			|| (*token_queue)->token.type == OR_IF_TOKEN))
		return (create_tree_parent(input,
				token_queue, heredoc_queue, node));
	return (1);
}
