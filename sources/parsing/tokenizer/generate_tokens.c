/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_tokens.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 23:19:00 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/13 03:44:42 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	add_token_to_queue(t_token_queue **queue, t_token token)
{
	t_token_queue	*element;

	element = ft_queuenew(token);
	if (!element)
		return (0);
	ft_queuepush(queue, element);
	return (1);
}

bool	generate_ordinary_tokens(t_cstr *input,
			t_token_queue **token_queue, t_token_queue **delimiter_queue)
{
	t_token	token;

	while (input->str[input->cursor] && (!(*token_queue)
			|| ft_queuelast(*token_queue)->token.type != NEWLINE_TOKEN))
	{
		if (!delimit_token(input, &token.content))
			return (0);
		if (!token.content.len)
		{
			input->cursor++;
			continue ;
		}
		input->cursor += token.content.len;
		token = lstr_to_token(token.content);
		if (*token_queue
			&& ft_queuelast(*token_queue)->token.type == DLESS_TOKEN
			&& token.type == WORD_TOKEN)
			if (!add_token_to_queue(delimiter_queue, token))
				return (0);
		if (!add_token_to_queue(token_queue, token))
			return (0);
	}
	return (1);
}

bool	get_delimiter(t_delimiter *delimiter, t_token_queue **delimiter_queue)
{
	t_lstr	delimiter_lstr;

	delimiter_lstr = (*delimiter_queue)->token.content;
	free(ft_queuepop(delimiter_queue));
	if (!ft_charsetisinlstr("\'\"", delimiter_lstr))
	{
		delimiter->was_quoted = false;
		delimiter->str
			= ft_substrrange(delimiter_lstr.str, 0, delimiter_lstr.len - 1);
		if (!delimiter->str)
			return (0);
		return (1);
	}
	delimiter->was_quoted = true;
	delimiter->str = remove_quotes(
			ft_substrrange(delimiter_lstr.str, 0, delimiter_lstr.len - 1));
	if (!delimiter->str)
		return (0);
	return (1);
}

bool	generate_heredocs(t_cstr *input,
			t_token_queue **delimiter_queue, t_token_queue **heredoc_queue)
{
	t_delimiter	delimiter;

	while (*delimiter_queue)
	{
		if (!get_delimiter(&delimiter, delimiter_queue))
			return (0);
	}
	return (1);
}

bool	generate_tokens(t_cstr *input,
			t_token_queue **token_queue, t_token_queue **heredoc_queue)
{
	t_token_queue	*delimiter_queue;

	input->cursor = 0;
	*token_queue = NULL;
	*heredoc_queue = NULL;
	delimiter_queue = NULL;
	while (input->str[input->cursor])
	{
		if (!generate_ordinary_tokens(input, token_queue, &delimiter_queue))
		{
			ft_queuefree(delimiter_queue);
			return (0);
		}
		disp_queue(*token_queue);
		if (!generate_heredocs(input, &delimiter_queue, heredoc_queue))
		{
			ft_queuefree(delimiter_queue);
			return (0);
		}
	}
	return (1);
}
