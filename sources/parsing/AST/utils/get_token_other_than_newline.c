/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token_other_than_newline.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 05:37:48 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/23 05:37:58 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	get_token_other_than_newline(t_cstr *input, t_token_queue **token_queue,
			t_token_queue **heredoc_queue)
{
	skip_newlines(token_queue);
	while (!(*token_queue))
		if (!update_token_queue(input, token_queue, heredoc_queue))
			return (0);
	return (1);
}
