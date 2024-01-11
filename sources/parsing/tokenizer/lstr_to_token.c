/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstr_to_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 22:55:57 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/11 13:11:03 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_token	lstr_to_operator_token(t_lstr lstr)
{
	if (lstr.str[0] == '&' && lstr.len == 2)
		return (((t_token){AND_IF_TOKEN, lstr}));
	if (lstr.str[0] == '|' && lstr.len == 2)
		return (((t_token){OR_IF_TOKEN, lstr}));
	if (lstr.str[0] == '<' && lstr.len == 2)
		return (((t_token){DLESS_TOKEN, lstr}));
	if (lstr.str[0] == '>' && lstr.len == 2)
		return (((t_token){DGREAT_TOKEN, lstr}));
	if (lstr.str[0] == '|' && lstr.len == 1)
		return (((t_token){PIPE_TOKEN, lstr}));
	if (lstr.str[0] == '<' && lstr.len == 1)
		return (((t_token){LESS_TOKEN, lstr}));
	if (lstr.str[0] == '>' && lstr.len == 1)
		return (((t_token){GREAT_TOKEN, lstr}));
	if (lstr.str[0] == '(' && lstr.len == 1)
		return (((t_token){LPAR_TOKEN, lstr}));
	if (lstr.str[0] == ')' && lstr.len == 1)
		return (((t_token){RPAR_TOKEN, lstr}));
	return (((t_token){WORD_TOKEN, lstr}));
}

t_token	lstr_to_token(t_lstr lstr)
{
	if (is_operator(lstr))
		return (lstr_to_operator_token(lstr));
	if (lstr.str[0] == '\n')
		return ((t_token){NEWLINE_TOKEN, lstr});
	return (((t_token){WORD_TOKEN, lstr}));
}
