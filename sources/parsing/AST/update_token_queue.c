/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_token_queue.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 22:47:36 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/18 22:50:01 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	update_token_queue(t_cstr *input,
			t_token_queue **token_queue, t_token_queue **heredoc_queue)
{
	if (!update_input(input))
		return (0);
	if (!generate_tokens(input, token_queue, heredoc_queue))
		return (0);
	return (1);
}
