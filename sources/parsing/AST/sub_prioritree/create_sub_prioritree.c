/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sub_prioritree.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 04:28:07 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/27 06:35:12 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	create_sub_prioritree(t_cstr *input, t_token_queue **token_queue,
			t_token_queue **heredoc_queue, t_node **node)
{
	free(ft_queuepop(token_queue));
	if (!get_token_other_than_newline(input, token_queue, heredoc_queue)
		|| !init_node(node))
		return (0);
	if (!create_child(input, token_queue, heredoc_queue, &(*node)->left_child))
		return (free(*node), 0);
	if (has_wrong_synthax(node, (*node)->left_child)
		|| is_sub_prioritree_left_child(input, token_queue,
			heredoc_queue, node))
		return (1);
	(*node)->left_child->parent = *node;
	if (!is_and_or_token(token_queue, node))
		return (1);
	if (!get_token_other_than_newline(input, token_queue, heredoc_queue))
		return (free_ast(*node), 0);
	if (!create_child(input, token_queue, heredoc_queue, &(*node)->right_child))
		return (free_ast(*node), 0);
	if (has_wrong_synthax(node, (*node)->right_child))
		return (1);
	(*node)->right_child->parent = *node;
	if ((*token_queue) && ((*token_queue)->token.type == AND_IF_TOKEN
			|| (*token_queue)->token.type == OR_IF_TOKEN))
		return (create_prioritree_parent(input, token_queue,
				heredoc_queue, node));
	return (find_right_par(input, token_queue, heredoc_queue, node));
}
