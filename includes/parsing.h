/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 14:28:10 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/08 21:38:10 by ekhaled          ###   ########.fr       */
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

typedef struct s_token
{
	enum e_token_type	type;
	t_lstr				content;
}	t_token;

typedef struct s_token_queue
{
	t_token						token;
	struct s_token_queue		*next;
}	t_token_queue;

t_token_queue	*ft_queuenew(t_token content);
t_token_queue	*ft_queuelast(t_token_queue *queue);
void			ft_queuepush(t_token_queue **queue, t_token_queue *new);
t_token_queue	*ft_queuepop(t_token_queue **queue);
void			ft_queuefree(t_token_queue *queue);


bool	is_word(t_lstr word_candidate);
bool	is_name(t_lstr name_candidate);

#endif