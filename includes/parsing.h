/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 14:28:10 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/22 03:45:23 by ekhaled          ###   ########.fr       */
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
	AND_IF_TOKEN,
	OR_IF_TOKEN,
	PIPE_TOKEN,
	LPAR_TOKEN,
	RPAR_TOKEN
};

typedef struct s_lstr
{
	char			*str;
	unsigned int	len;
}	t_lstr;

typedef struct s_cstr
{
	char			*str;
	unsigned int	cursor;
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
	bool	is_in;
	char	type;
}	t_quotes;

typedef struct s_delimiter
{
	char		*str;
	bool		was_quoted;
}	t_delimiter;

/*-------- AST --------*/

enum e_node_type
{
	AND_NODE,
	OR_NODE,
	PIPE_NODE,
	CMD_NODE
};

enum e_redir_type
{
	INPUT_REDIR,
	HEREDOC_REDIR,
	OUTPUT_REDIR,
	OUTPUT_APPEND_REDIR
};

typedef struct s_redir
{
	enum e_redir_type	type;
	union
	{
		char			*file;
		char			*heredoc;
	};
}	t_redir;

typedef struct s_cmd
{
	char		*cmd_name;
	char		**cmd_args;
	t_redir		input_redir;
	t_redir		output_redir;
}	t_cmd;

typedef struct s_node			t_node;

typedef struct s_node
{
	enum e_node_type	type;
	t_node				*parent;
	t_node				*left_child;
	t_node				*right_child;
	t_cmd				cmd;
}	t_node;

typedef t_node					*t_ast;

bool			generate_ast(t_cstr *input, t_token_queue **token_queue,
					t_token_queue **heredoc_queue, t_ast *ast);
bool			create_sub_tree(t_cstr *input, t_token_queue **token_queue,
					t_token_queue **heredoc_queue, t_ast *ast);
bool			update_token_queue(t_cstr *input,
					t_token_queue **token_queue, t_token_queue **heredoc_queue);

bool			create_pipe_sub_tree(t_cstr *input, t_token_queue **token_queue,
					t_token_queue **heredoc_queue, t_node **node);
bool			create_pipe_parent(t_cstr *input, t_token_queue **token_queue,
					t_token_queue **heredoc_queue, t_node **node);

bool			has_wrong_synthax(t_node **node, t_node *child);
void			skip_newlines(t_token_queue **token_queue);

bool			create_leaf(t_cstr *input, t_token_queue **token_queue,
					t_token_queue **heredoc_queue, t_node **leaf);
bool			update_cmd(t_token_queue **token_queue,
					t_token_queue **heredoc_queue, t_node **leaf,
					enum e_redir_type *next_redir_type);
bool			try_to_update_redir_files(t_token_queue *token_el,
					t_token_queue **heredoc_queue,
					t_node **leaf, enum e_redir_type *next_redir_type);
bool			update_redir_files(t_token token, t_token_queue **heredoc_queue,
					t_cmd *cmd, enum e_redir_type redir_type);
void			update_redir_types(t_token token, t_cmd *cmd,
					enum e_redir_type *redir_type);
bool			init_node(t_node **node);
void			init_cmd(t_cmd *cmd);
void			free_cmd(t_cmd *cmd);
void			free_ast(t_ast ast);

void			update_quoting(t_quotes *quotes, char *str, int i);

char			*expand_parameters(char *str, t_session *session);
char			*match_patterns(char *str);
char			*remove_quotes(char *str);

bool			is_matching_file(char *str, char *file);
bool			has_interpretable_asterisk(char *str);
int				find_first_asterisk(char *str);
int				find_last_asterisk(char *str);
bool			are_patterns_found(char *str, char *file,
					int first_asterisk_index, int last_asterisk_index);
bool			is_pattern_in(char *matching_leftover_str,
					int pattern_start, int pattern_end, t_lstr *available_file);
char			*create_new_str(char *str, char **matching_files);



t_token_queue	*ft_queuenew(t_token content);
t_token_queue	*ft_queuelast(t_token_queue *queue);
void			ft_queuepush(t_token_queue **queue, t_token_queue *new);
t_token_queue	*ft_queuepop(t_token_queue **queue);
unsigned int	ft_queuelen(t_token_queue *queue);
void			ft_queuefree(t_token_queue *queue);
void			ft_queuefreeall(t_token_queue *queue);


bool			is_word(t_lstr word_candidate);
bool			is_operator(t_lstr op_candidate);
bool			is_name(t_lstr name_candidate);

bool			generate_tokens(t_cstr *input, t_token_queue **token_queue,
					t_token_queue **heredoc_queue);
bool			generate_heredocs(t_cstr *input,
					t_token_queue **token_queue,
					t_token_queue **delimiter_queue,
					t_token_queue **heredoc_queue);
bool			generate_ordinary_tokens(t_cstr *input,
					t_token_queue **token_queue,
					t_token_queue **delimiter_queue);
t_lstr			get_token(t_quotes *quotes, unsigned int *i, t_cstr *input);
void			update_queues(char *old_input, char *new_input,
					t_token_queue *token_queue, t_token_queue *delimiter_queue);
t_token			lstr_to_token(t_lstr lstr);
bool			add_token_to_queue(t_token_queue **queue, t_token token);

bool			read_input(t_session *session, t_cstr *input);
bool			update_input(t_cstr *input);

#endif