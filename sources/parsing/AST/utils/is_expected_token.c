/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_expected_token.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 05:40:23 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/27 06:36:43 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_and_or_token(t_token_queue **token_queue, t_node **node)
{
	t_token_queue	*token_el;

	token_el = ft_queuepop(token_queue);
	if (token_el->token.type != AND_IF_TOKEN
		&& token_el->token.type != OR_IF_TOKEN)
	{
		disp_token_error(token_el->token.type);
		free_ast(*node);
		*node = NULL;
		free(token_el);
		return (false);
	}
	(*node)->type = get_node_type(token_el->token.type);
	free(token_el);
	return (true);
}

bool	is_pipe_token(t_token_queue **token_queue, t_node **node)
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
	(*node)->type = get_node_type(token_el->token.type);
	free(token_el);
	return (true);
}
