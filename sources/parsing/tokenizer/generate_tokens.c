/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_tokens.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 23:19:00 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/10 23:43:21 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	generate_tokens(t_cstr *input, t_token_queue **token_queue)
{
	t_token	token;

	input->cursor = 0;
	while ((!input->cursor || input->str[input->cursor - 1])
		&& input->str[input->cursor])
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
	}
	return (1);
}
