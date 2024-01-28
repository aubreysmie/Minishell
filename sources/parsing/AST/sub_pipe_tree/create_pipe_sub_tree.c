/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pipe_sub_tree.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 00:33:04 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/27 06:28:12 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "minishell.h"

bool	create_pipe_sub_tree(t_cstr *input, t_token_queue **token_queue,
			t_token_queue **heredoc_queue, t_node **node)
{
	if (!init_node(node))
		return (0);
	if (!create_leaf(input, token_queue, heredoc_queue, &(*node)->left_child))
		return (free(*node), 0);
	if (has_wrong_synthax(node, (*node)->left_child)
		|| is_pipe_sub_tree_left_child(token_queue, node))
		return (1);
	(*node)->left_child->parent = *node;
	(*node)->type = PIPE_NODE;
	free(ft_queuepop(token_queue));
	if (!get_token_other_than_newline(input, token_queue, heredoc_queue))
		return (free_ast(*node), 0);
	if (!create_leaf(input, token_queue, heredoc_queue, &(*node)->right_child))
		return (free_ast(*node), 0);
	if (has_wrong_synthax(node, (*node)->right_child))
		return (1);
	(*node)->right_child->parent = *node;
	if ((*token_queue) && (*token_queue)->token.type == PIPE_TOKEN)
		return (create_pipe_tree_parent(input, token_queue,
				heredoc_queue, node));
	return (1);
}
