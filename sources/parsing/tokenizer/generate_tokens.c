/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_tokens.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 23:19:00 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/14 20:15:07 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	add_token_to_queue(t_token_queue **queue, t_token token)
{
	t_token_queue	*element;

	element = ft_queuenew(token);
	if (!element)
		return (0);
	ft_queuepush(queue, element);
	return (1);
}

bool	generate_tokens(t_cstr *input,
			t_token_queue **token_queue, t_token_queue **heredoc_queue)
{
	t_token_queue	*delimiter_queue;

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
		if (!generate_heredocs(input, token_queue, &delimiter_queue,
				heredoc_queue))
		{
			ft_queuefree(delimiter_queue);
			return (0);
		}
	}
	return (1);
}
