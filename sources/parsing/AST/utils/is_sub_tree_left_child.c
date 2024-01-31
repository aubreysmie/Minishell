/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sub_tree_left_child.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 05:35:47 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/31 14:20:23 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_pipe_sub_tree_left_child(t_token_queue **token_queue, t_node **node)
{
	t_node	*leaf;

	leaf = (*node)->left_child;
	if (!(*token_queue) || (*token_queue)->token.type != PIPE_TOKEN)
	{
		free(*node);
		*node = leaf;
		return (true);
	}
	return (false);
}

bool	is_sub_prioritree_left_child(t_cstr *input, t_token_queue **token_queue,
			t_token_queue **heredoc_queue, t_node **node)
{
	t_node	*left_child;

	skip_newlines(token_queue);
	while (!(*token_queue))
		if (!update_token_queue(input, token_queue, heredoc_queue))
			return (free_ast(*node), 0);
	left_child = (*node)->left_child;
	if ((*token_queue)->token.type == RPAR_TOKEN)
	{
		free(ft_queuepop(token_queue));
		free(*node);
		*node = left_child;
		return (true);
	}
	return (false);
}

bool	is_sub_tree_left_child(t_token_queue **token_queue, t_node **node)
{
	t_node	*leaf;

	leaf = (*node)->left_child;
	if (!(*token_queue) || (*token_queue)->token.type == NEWLINE_TOKEN)
	{
		free(*node);
		*node = leaf;
		return (true);
	}
	return (false);
}
