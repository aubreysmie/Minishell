/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_ordinary_tokens.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 17:52:43 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/22 03:38:02 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	delimit_token(t_cstr *input,
			t_lstr *token_lstr, t_token_queue *token_queue)
{
	static t_quotes		quotes = (t_quotes){false, 0};
	static unsigned int	i = 0;

	*token_lstr = get_token(&quotes, &i, input);
	if (!quotes.is_in)
	{
		i = 0;
		return (1);
	}
	if (!update_input(input))
		return (0);
	return (delimit_token(input, token_lstr, token_queue));
}

void	update_queues(char *old_input, char *new_input,
	t_token_queue *token_queue, t_token_queue *delimiter_queue)
{
	while (token_queue)
	{
		token_queue->token.content.str
			= token_queue->token.content.str - old_input + new_input;
		token_queue = token_queue->next;
	}
	while (delimiter_queue)
	{
		delimiter_queue->token.content.str
			= delimiter_queue->token.content.str - old_input + new_input;
		delimiter_queue = delimiter_queue->next;
	}
}

bool	generate_ordinary_tokens(t_cstr *input,
			t_token_queue **token_queue, t_token_queue **delimiter_queue)
{
	t_token	token;
	char	*old_input_str;

	while (input->str[input->cursor] && (!(*delimiter_queue) || (!(*token_queue)
			|| ft_queuelast(*token_queue)->token.type != NEWLINE_TOKEN)))
	{
		old_input_str = input->str;
		if (!delimit_token(input, &token.content, *token_queue))
			return (0);
		if (old_input_str != input->str)
			update_queues(old_input_str, input->str,
				*token_queue, *delimiter_queue);
		input->cursor += ft_max(1, token.content.len);
		if (!token.content.len)
			continue ;
		token = lstr_to_token(token.content);
		if (token.type == WORD_TOKEN && *token_queue
			&& ft_queuelast(*token_queue)->token.type == DLESS_TOKEN)
			if (!add_token_to_queue(delimiter_queue, token))
				return (0);
		if (!add_token_to_queue(token_queue, token))
			return (0);
	}
	return (1);
}
