/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 14:28:10 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/06 22:01:11 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdint.h>
# include <stdbool.h>

typedef struct s_lstr
{
	char		*str;
	uint32_t	len;
}	t_lstr;

// bool	run_repl(t_session *session);

bool	is_word(t_lstr word_candidate);
bool	is_name(t_lstr name_candidate);

#endif