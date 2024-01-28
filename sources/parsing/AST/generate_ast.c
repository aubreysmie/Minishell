/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_ast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 02:58:52 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/28 22:30:28 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	generate_ast(t_cstr *input, t_token_queue **token_queue,
			t_token_queue **heredoc_queue, t_ast *ast)
{
	if (!create_sub_tree(input, token_queue, heredoc_queue, ast))
		return (0);
	if (!(*ast))
		while ((*token_queue) && (*token_queue)->token.type != NEWLINE_TOKEN)
			free(ft_queuepop(token_queue));
	return (1);
}
