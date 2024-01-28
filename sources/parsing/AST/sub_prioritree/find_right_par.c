/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_right_par.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 05:36:58 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/23 05:37:07 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	find_right_par(t_cstr *input, t_token_queue **token_queue,
			t_token_queue **heredoc_queue, t_node **node)
{
	if (!get_token_other_than_newline(input, token_queue, heredoc_queue))
		return (free_ast(*node), 0);
	if ((*token_queue)->token.type == RPAR_TOKEN)
	{
		free(ft_queuepop(token_queue));
		return (1);
	}
	disp_token_error((*token_queue)->token.type);
	free_ast(*node);
	*node = NULL;
	return (1);
}
