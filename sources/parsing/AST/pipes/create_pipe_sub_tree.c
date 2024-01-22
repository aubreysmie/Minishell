/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pipe_sub_tree.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 00:33:04 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/22 04:13:55 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "minishell.h"

bool	is_sub_tree_leaf(t_token_queue **token_queue, t_node **node)
{
	t_node	*leaf;

	leaf = (*node)->left_child;
	if (!(*token_queue) || (*token_queue)->token.type == NEWLINE)
	{
		free(*node);
		*node = leaf;
		return (true);
	}
	return (false);
}

bool	is_pipe_op(t_token_queue **token_queue, t_node **node)
{
	t_token_queue	*token_el;

	token_el = ft_queuepop(token_queue);
	if (token_el->token.type != PIPE_TOKEN)
	{
		disp_token_error(token_el->token.type);
		free_ast(*node);
		*node = NULL;
		free(token_el);
		return (false);
	}
	(*node)->type = PIPE_NODE;
	free(token_el);
	return (true);
}

bool	create_pipe_sub_tree(t_cstr *input, t_token_queue **token_queue,
			t_token_queue **heredoc_queue, t_node **node)
{
	if (!init_node(node))
		return (0);
	if (!create_leaf(input, token_queue, heredoc_queue, &(*node)->left_child))
		return (free(*node), 0);
	if (has_wrong_synthax(node, (*node)->left_child)
		|| is_sub_tree_leaf(token_queue, node))
		return (1);
	(*node)->left_child->parent = *node;
	if (!is_pipe_op(token_queue, node))
		return (1);
	skip_newlines(token_queue);
	while (!(*token_queue))
		if (!update_token_queue(input, token_queue, heredoc_queue))
			return (free_ast(*node), 0);
	if (!create_leaf(input, token_queue, heredoc_queue, &(*node)->right_child))
		return (free_ast(*node), 0);
	if (has_wrong_synthax(node, (*node)->right_child))
		return (1);
	(*node)->right_child->parent = *node;
	if ((*token_queue) && (*token_queue)->token.type == PIPE_TOKEN)
		return (create_pipe_parent(input, token_queue, heredoc_queue, node));
	return (1);
}
