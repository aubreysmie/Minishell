/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 14:28:10 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/10 17:24:44 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdint.h>
# include <stdbool.h>

typedef struct s_session	t_session;

/*-------- Tokenizer --------*/

enum e_token_type
{
	DLESS_TOKEN,
	DGREAT_TOKEN,
	LESS_TOKEN,
	GREAT_TOKEN,
	WORD_TOKEN,
	NEWLINE_TOKEN,
	IO_NUMBER_TOKEN,
	AND_IF_TOKEN,
	OR_IF_TOKEN,
	PIPE_TOKEN,
	LPAR_TOKEN,
	RPAR_TOKEN
};

typedef struct s_lstr
{
	char		*str;
	uint32_t	len;
}	t_lstr;

typedef struct s_cstr
{
	char		*str;
	uint32_t	cursor;
}	t_cstr;

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

typedef struct s_quotes
{
	bool	in;
	char	type;
}	t_quotes;

t_token_queue	*ft_queuenew(t_token content);
t_token_queue	*ft_queuelast(t_token_queue *queue);
void			ft_queuepush(t_token_queue **queue, t_token_queue *new);
t_token_queue	*ft_queuepop(t_token_queue **queue);
void			ft_queuefree(t_token_queue *queue);

bool			is_word(t_lstr word_candidate);
bool			is_operator(t_lstr op_candidate);
bool			is_name(t_lstr name_candidate);

bool			generate_tokens(t_cstr *input, t_token_queue **token_queue);
bool			delimit_token(t_cstr *input, t_lstr *token_lstr);

bool			read_input(t_session *session, char **input_str);

#endif