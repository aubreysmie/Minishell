/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_operator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 22:40:25 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/30 07:43:03 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "parsing.h"

bool	is_operator(t_lstr op_candidate)
{
	if (op_candidate.len == 1
		&& (op_candidate.str[0] == '|'
			|| op_candidate.str[0] == '('
			|| op_candidate.str[0] == ')'
			|| op_candidate.str[0] == '<'
			|| op_candidate.str[0] == '>'))
		return (1);
	if (op_candidate.len == 2
		&& ((op_candidate.str[0] == '&' && op_candidate.str[1] == '&')
			|| (op_candidate.str[0] == '|' && op_candidate.str[1] == '|')
			|| (op_candidate.str[0] == '<' && op_candidate.str[1] == '<')
			|| (op_candidate.str[0] == '>' && op_candidate.str[1] == '>')))
		return (1);
	return (0);
}
