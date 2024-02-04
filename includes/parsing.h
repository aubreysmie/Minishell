/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 14:28:10 by ekhaled           #+#    #+#             */
/*   Updated: 2024/02/04 15:39:33 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdint.h>
# include <stdbool.h>

typedef struct s_session		t_session;

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
	int				cursor;
}	t_cstr;

typedef struct s_token
{
	enum e_token_type	type;
	t_lstr				content;
}	t_token;

typedef struct s_token_queue	t_token_queue;

typedef struct s_token_queue
{
	t_token				token;
	t_token_queue		*next;
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
	AND_IF_NODE,
	OR_IF_NODE,
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

/*-------- Expansions --------*/

typedef struct s_range
{
	bool	is_quoted;
	int		start;
	int		end;
}	t_range;

typedef struct s_range_array
{
	t_range		*array;
	int			len;
}	t_range_array;

typedef struct s_exp_str
{
	bool			is_expanded;
	t_range_array	range_array;
	char			*str;
}	t_exp_str;

typedef struct s_exp_str_array
{
	t_exp_str	*array;
	int			len;
}	t_exp_str_array;

bool				create_pipe_sub_tree(t_cstr *input,
						t_token_queue **token_queue,
						t_token_queue **heredoc_queue,
						t_node **node);
bool				create_pipe_tree_parent(t_cstr *input,
						t_token_queue **token_queue,
						t_token_queue **heredoc_queue,
						t_node **node);

bool				create_sub_prioritree(t_cstr *input,
						t_token_queue **token_queue,
						t_token_queue **heredoc_queue,
						t_node **node);
bool				create_prioritree_parent(t_cstr *input,
						t_token_queue **token_queue,
						t_token_queue **heredoc_queue,
						t_node **node);
bool				find_right_par(t_cstr *input,
						t_token_queue **token_queue,
						t_token_queue **heredoc_queue,
						t_node **node);

bool				create_sub_tree(t_cstr *input,
						t_token_queue **token_queue,
						t_token_queue **heredoc_queue,
						t_ast *ast);
bool				create_tree_parent(t_cstr *input,
						t_token_queue **token_queue,
						t_token_queue **heredoc_queue,
						t_node **node);

bool				create_leaf(t_cstr *input,
						t_token_queue **token_queue,
						t_token_queue **heredoc_queue,
						t_node **leaf);
bool				update_cmd(t_token_queue **token_queue,
						t_token_queue **heredoc_queue,
						t_node **leaf,
						enum e_redir_type *next_redir_type);
bool				try_to_update_redir_files(t_token_queue *token_el,
						t_token_queue **heredoc_queue,
						t_node **leaf,
						enum e_redir_type *next_redir_type);
bool				update_redir_files(t_token token,
						t_token_queue **heredoc_queue,
						t_cmd *cmd,
						enum e_redir_type redir_type);
void				update_redir_types(t_token token,
						t_cmd *cmd,
						enum e_redir_type *redir_type);
void				init_cmd(t_cmd *cmd);
void				free_cmd(t_cmd *cmd);

bool				create_child(t_cstr *input,
						t_token_queue **token_queue,
						t_token_queue **heredoc_queue,
						t_node **left_child);
bool				get_token_other_than_newline(t_cstr *input,
						t_token_queue **token_queue,
						t_token_queue **heredoc_queue);
enum e_node_type	get_node_type(enum e_token_type token_type);

bool				has_wrong_synthax(t_node **node,
						t_node *child);
bool				is_and_or_token(t_token_queue **token_queue,
						t_node **node);
bool				is_pipe_token(t_token_queue **token_queue,
						t_node **node);
bool				is_pipe_sub_tree_left_child(t_token_queue **token_queue,
						t_node **node);
bool				is_sub_prioritree_left_child(t_cstr *input,
						t_token_queue **token_queue,
						t_token_queue **heredoc_queue,
						t_node **node);
bool				is_sub_tree_left_child(t_token_queue **token_queue,
						t_node **node);
void				skip_newlines(t_token_queue **token_queue);
bool				update_token_queue(t_cstr *input,
						t_token_queue **token_queue,
						t_token_queue **heredoc_queue);

bool				generate_ast(t_cstr *input,
						t_token_queue **token_queue,
						t_token_queue **heredoc_queue,
						t_ast *ast);
bool				init_node(t_node **node);
void				free_ast(t_ast ast);

void				update_quoting(t_quotes *quotes,
						char *str,
						int i);

char				**apply_expansions(char *str,
						t_session *session);

bool				ft_expstraadd(t_exp_str_array *exp_str_array,
						t_exp_str new_exp_str);
bool				ft_rangeaadd(t_range_array *range_array,
						t_range new_range);
bool				add_wildcards_exp(t_exp_str_array *exp_str_array);
bool				ft_expstrajoin(t_exp_str_array *exp_str_array1,
						t_exp_str_array *exp_str_array2);
t_range_array		ft_rangearraydup(t_range_array range_array);
t_exp_str			ft_expstrdup(t_exp_str exp_str);
void				ft_expstrafree(t_exp_str_array exp_str_array);
char				**ft_splitset_unquoted_expansions(char const *s,
						t_range_array *range_array,
						char set[]);
bool				is_accepted_del_index(int index_candidate,
						t_range_array range_array);
bool				is_index_in_range(int index,
						t_range_array *range_array,
						bool *is_quoted);
bool				stra_to_exp_stra(char **str_array,
						t_range_array *range_array,
						t_exp_str_array *exp_str_array);
void				update_range_offset(t_range_array *range_array,
						int offset);
char				**remove_quotes_stra(t_exp_str_array exp_str_array);

bool				append_between_vars_str(char **expanded_str_p,
						char *str,
						int var_end,
						int i);
char				*find_variable_value(t_lstr name,
						t_session *session);
bool				append_last_cmd_status(char **expanded_str_p,
						int *i_p,
						int last_cmd_status);
bool				append_var_str(char **expanded_str_p,
						char *str,
						int *i_p,
						t_session *session);

bool				expand_parameters_and_save_range(char *str,
						t_session *session,
						t_exp_str *exp_str);
char				*expand_parameters(char *str,
						t_session *session);
char				**match_patterns(char *str);
char				*remove_quotes(char *str);

bool				is_matching_file(char *str,
						char *file);
bool				has_interpretable_asterisk(char *str);
int					find_first_asterisk(char *str);
int					find_last_asterisk(char *str);
bool				are_patterns_found(char *str,
						char *file,
						int first_asterisk_index,
						int last_asterisk_index);
bool				is_pattern_in(char *matching_leftover_str,
						int pattern_start,
						int pattern_end,
						t_lstr *available_file);
char				**create_new_stra(char *str,
						char **matching_files);

t_token_queue		*ft_queuenew(t_token content);
t_token_queue		*ft_queuelast(t_token_queue *queue);
void				ft_queuepush(t_token_queue **queue, t_token_queue *new);
t_token_queue		*ft_queuepop(t_token_queue **queue);
unsigned int		ft_queuelen(t_token_queue *queue);
void				ft_queuefree(t_token_queue *queue);
void				ft_queuefreeall(t_token_queue *queue);

bool				is_word(t_lstr word_candidate);
bool				is_operator(t_lstr op_candidate);
bool				is_name(t_lstr name_candidate);

bool				generate_tokens(t_cstr *input,
						t_token_queue **token_queue,
						t_token_queue **heredoc_queue);
bool				generate_ordinary_tokens(t_cstr *input,
						t_token_queue **token_queue,
						t_token_queue **delimiter_queue);
bool				generate_heredocs(t_cstr *input,
						t_token_queue **token_queue,
						t_token_queue **delimiter_queue,
						t_token_queue **heredoc_queue);
t_lstr				get_token(t_quotes *quotes,
						unsigned int *i,
						t_cstr *input);
bool				get_heredoc(t_cstr *input,
						char *delimiter,
						char **heredoc);
void				update_queues(char *old_input,
						char *new_input,
						t_token_queue *token_queue,
						t_token_queue *delimiter_queue);
t_token				lstr_to_token(t_lstr lstr);
bool				add_token_to_queue(t_token_queue **queue,
						t_token token);

bool				read_input(t_session *session,
						t_cstr *input);
bool				update_input(t_cstr *input);

#endif
