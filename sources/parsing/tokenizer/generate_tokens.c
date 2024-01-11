/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_tokens.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 23:19:00 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/11 22:26:37 by ekhaled          ###   ########.fr       */
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

bool	generate_tokens(t_cstr *input, t_token_queue **token_queue)
{
	t_token	token;

	input->cursor = 0;
	*token_queue = NULL;
	while (input->str[input->cursor])
	{
		if (!delimit_token(input, &token.content))
		{
			ft_queuefree(*token_queue);
			return (0);
		}
		if (!token.content.len)
		{
			input->cursor++;
			continue ;
		}
		input->cursor += token.content.len;
		token = lstr_to_token(token.content);
		if (!add_token_to_queue(token_queue, token))
		{
			ft_queuefree(*token_queue);
			return (0);
		}
	}
	return (1);
}
