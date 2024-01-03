/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_word.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 23:26:50 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/03 16:05:29 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "utils.h"

bool	is_word(char *word_candidate)
{
	if (ft_strlen(word_candidate) == 1
		&& (word_candidate[0] == '|'
			|| word_candidate[0] == '('
			|| word_candidate[0] == ')'
			|| word_candidate[0] == '<'
			|| word_candidate[0] == '>'))
		return (0);
	if (ft_strlen(word_candidate) == 2
		&& ((word_candidate[0] == '&' && word_candidate[1] == '&')
			|| (word_candidate[0] == '|' && word_candidate[1] == '|')
			|| (word_candidate[0] == '<' && word_candidate[1] == '<')
			|| (word_candidate[0] == '>' && word_candidate[1] == '>')))
		return (0);
	return (1);
}
