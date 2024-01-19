/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp_token_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 23:46:24 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/19 18:59:49 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "parsing.h"
#include "error.h"

void	disp_token(enum e_token_type token_type)
{
	if (token_type == DLESS_TOKEN)
		write(2, "<<", 2);
	if (token_type == DGREAT_TOKEN)
		write(2, ">>", 2);
	if (token_type == LESS_TOKEN)
		write(2, "<", 1);
	if (token_type == GREAT_TOKEN)
		write(2, ">", 1);
	if (token_type == NEWLINE_TOKEN)
		write(2, "newline", 7);
	if (token_type == AND_IF_TOKEN)
		write(2, "&&", 2);
	if (token_type == OR_IF_TOKEN)
		write(2, "||", 2);
	if (token_type == PIPE_TOKEN)
		write(2, "|", 1);
	if (token_type == LPAR_TOKEN)
		write(2, "(", 1);
	if (token_type == RPAR_TOKEN)
		write(2, ")", 1);
}

void	disp_token_error(enum e_token_type token_type)
{
	write(2, "minishell", 9);
	write(2, ": ", 2);
	write(2, "syntax error near unexpected token ", 35);
	write(2, "`", 1);
	disp_token(token_type);
	write(2, "'", 1);
	write(2, "\n", 1);
}
