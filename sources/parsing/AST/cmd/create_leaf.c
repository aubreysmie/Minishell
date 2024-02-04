/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_leaf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 22:51:28 by ekhaled           #+#    #+#             */
/*   Updated: 2024/02/04 18:34:51 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_leaf_allowed_token(enum e_token_type token_type)
{
	if (token_type == WORD_TOKEN
		|| token_type == DLESS_TOKEN || token_type == LESS_TOKEN
		|| token_type == DGREAT_TOKEN || token_type == GREAT_TOKEN)
		return (1);
	return (0);
}

bool	fill_leaf(t_token_queue **token_queue,
			t_token_queue **heredoc_queue, t_node **leaf)
{
	enum e_redir_type	next_redir_type;

	next_redir_type = -1;
	(*leaf)->type = CMD_NODE;
	while ((*token_queue) && is_leaf_allowed_token((*token_queue)->token.type))
	{
		if (!update_cmd(token_queue, heredoc_queue, leaf, &next_redir_type))
			return (free_cmd(&(*leaf)->cmd), 0);
		if (!(*leaf))
			return (1);
		free(ft_queuepop(token_queue));
	}
	if (next_redir_type != (enum e_redir_type)(-1))
	{
		if (*token_queue)
			disp_token_error((*token_queue)->token.type);
		else
			disp_token_error(NEWLINE_TOKEN);
		free_cmd(&(*leaf)->cmd);
		free(*leaf);
		*leaf = NULL;
	}
	return (1);
}

bool	create_leaf(t_cstr *input, t_token_queue **token_queue,
			t_token_queue **heredoc_queue, t_node **leaf)
{
	if (!(*token_queue))
		if (!update_token_queue(input, token_queue, heredoc_queue))
			return (0);
	if (!is_leaf_allowed_token((*token_queue)->token.type))
	{
		disp_token_error((*token_queue)->token.type);
		*leaf = NULL;
		return (1);
	}
	if (!init_node(leaf))
		return (0);
	if (!fill_leaf(token_queue, heredoc_queue, leaf))
	{
		free(leaf);
		return (0);
	}
	return (1);
}
