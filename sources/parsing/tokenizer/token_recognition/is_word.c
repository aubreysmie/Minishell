/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_word.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 23:26:50 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/09 22:40:55 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "parsing.h"

bool	is_word(t_lstr word_candidate)
{
	if (word_candidate.len == 1
		&& (word_candidate.str[0] == '|'
			|| word_candidate.str[0] == '('
			|| word_candidate.str[0] == ')'
			|| word_candidate.str[0] == '<'
			|| word_candidate.str[0] == '>'))
		return (0);
	if (word_candidate.len == 2
		&& ((word_candidate.str[0] == '&' && word_candidate.str[1] == '&')
			|| (word_candidate.str[0] == '|' && word_candidate.str[1] == '|')
			|| (word_candidate.str[0] == '<' && word_candidate.str[1] == '<')
			|| (word_candidate.str[0] == '>' && word_candidate.str[1] == '>')))
		return (0);
	return (1);
}
