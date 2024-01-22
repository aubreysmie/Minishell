/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_newlines.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 03:44:15 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/22 03:52:20 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	skip_newlines(t_token_queue **token_queue)
{
	while ((*token_queue) && (*token_queue)->token.type == NEWLINE_TOKEN)
		free(ft_queuepop(token_queue));
}
