# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/27 21:02:35 by ekhaled           #+#    #+#              #
#    Updated: 2024/01/30 09:29:29 by ekhaled          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				:=	minishell


SRC_DIR				:=	sources
OBJ_DIR				:=	objects


SRCS_UTILS			:=	ft_atoui.c \
						ft_calloc.c \
						ft_charisinset.c \
						ft_charsetisinlstr.c \
						ft_isalnum.c \
						ft_isalpha.c \
						ft_isdigit.c \
						ft_lstrchrseti.c \
						ft_lstrcmp.c \
						ft_max.c \
						ft_min.c \
						ft_split.c \
						ft_splitset.c \
						ft_straadd.c \
						ft_straddcharfree.c \
						ft_stradup.c \
						ft_strafree.c \
						ft_strajoin.c \
						ft_strajoinfree.c \
						ft_stralen.c \
						ft_strareeq.c \
						ft_strarm.c \
						ft_strarp.c \
						ft_strchri.c \
						ft_strchrseti.c \
						ft_strcmp.c \
						ft_strcpy.c \
						ft_strdup.c \
						ft_strisinstr.c \
						ft_strisinstra.c \
						ft_strisnum.c \
						ft_strjoin.c \
						ft_strjoinfree.c \
						ft_strlen.c \
						ft_substrrange.c \
						ft_uitoa.c \
						get_next_line.c

SRCS_BUILTINS		:=	cd.c \
						echo.c \
						env.c \
						exit.c \
						export.c \
						pwd.c \
						unset.c

SRCS_ERRORS			:=	disp_access_error.c \
						disp_eof_warning.c \
						disp_token_error.c

SRCS_CMD			:=	create_leaf.c \
						free_cmd.c \
						init_cmd.c \
						update_cmd.c \
						update_redirs.c
SRCS_PIPE_TREE		:=	create_pipe_sub_tree.c \
						create_pipe_tree_parent.c 
SRCS_PRIORITREE		:=	create_prioritree_parent.c \
						create_sub_prioritree.c \
						find_right_par.c
SRCS_TREE			:=	create_sub_tree.c \
						create_tree_parent.c
SRCS_AST_UTILS		:=	create_child.c \
						get_node_type.c \
						get_token_other_than_newline.c \
						has_wrong_synthax.c \
						is_expected_token.c \
						is_sub_tree_left_child.c \
						skip_newlines.c \
						update_token_queue.c
SRCS_AST			:=	${addprefix cmd/, ${SRCS_CMD}} \
						${addprefix sub_pipe_tree/, ${SRCS_PIPE_TREE}} \
						${addprefix sub_prioritree/, ${SRCS_PRIORITREE}} \
						${addprefix sub_tree/, ${SRCS_TREE}} \
						${addprefix utils/, ${SRCS_AST_UTILS}} \
						free_ast.c \
						generate_ast.c \
						init_node.c

SRCS_WILDCARDS		:=	are_patterns_found.c \
						create_new_str.c \
						find_asterisks.c \
						is_matching_file.c \
						is_pattern_in.c \
						match_patterns.c
SRCS_EXPANSION		:=	${addprefix wildcards/, ${SRCS_WILDCARDS}} \
						expand_parameters.c \
						remove_quotes.c \
						update_quoting.c

SRCS_QUEUE			:=	ft_queuefree.c \
						ft_queuefreeall.c \
						ft_queuelast.c \
						ft_queuelen.c \
						ft_queuenew.c \
						ft_queuepop.c \
						ft_queuepush.c
SRCS_TOKEN_REC		:=	is_name.c \
						is_operator.c \
						is_word.c
SRCS_TOKENIZER		:=	${addprefix queue/, ${SRCS_QUEUE}} \
						${addprefix token_recognition/, ${SRCS_TOKEN_REC}} \
						generate_heredocs.c \
						generate_ordinary_tokens.c \
						generate_tokens.c \
						get_heredoc.c \
						get_token.c \
						lstr_to_token.c

SRCS_PARSING		:=	${addprefix AST/, ${SRCS_AST}} \
						${addprefix expansions/, ${SRCS_EXPANSION}} \
						${addprefix tokenizer/, ${SRCS_TOKENIZER}} \
						read_input.c \
						update_input.c

SRCS_EXEC_CMD		:=	execute_builtin.c \
						execute_cmd_node.c \
						execute_cmd.c

SRCS_EXEC_PIPES_CMD	:=	execute_pipe_sub_tree.c \
						execute_piped_builtin.c \
						execute_piped_cmd_node.c \
						execute_piped_cmd.c

SRCS_EXEC_UTILS		:=	change_io.c \
						destroy_and_exit.c \
						expand_cmd_args.c \
						expand_cmd_words.c \
						get_last_cmd_exit_status.c \
						is_cmd_builtin.c \
						manage_std_io.c \
						open_files.c \
						write_heredoc_in_pipe.c

SRCS_EXEC			:=	${addprefix exec_cmd/, ${SRCS_EXEC_CMD}} \
						${addprefix exec_pipes_cmds/, ${SRCS_EXEC_PIPES_CMD}} \
						${addprefix utils/, ${SRCS_EXEC_UTILS}} \
						call_builtin.c \
						call_cmd.c \
						execute_ast.c

SRCS_SESSION		:=	init_session.c \
						destroy_session.c

SRCS_MAIN			:=	main.c

SRCS				:=	${addprefix builtins/, ${SRCS_BUILTINS}} \
						${addprefix errors/, ${SRCS_ERRORS}} \
						${addprefix execution/, ${SRCS_EXEC}} \
						${addprefix parsing/, ${SRCS_PARSING}} \
						${addprefix session/, ${SRCS_SESSION}} \
						${addprefix utils/, ${SRCS_UTILS}} \
						${SRCS_MAIN}


SRCS				:=	${SRCS:%=${SRC_DIR}/%}
OBJS				:=	${SRCS:${SRC_DIR}/%.c=${OBJ_DIR}/%.o}


LIBFLAGS			:=	-lreadline
CFLAGS				:=	-Wall -Wextra -Werror
CPPFLAGS			:=	-I includes


RM					:=	${RM} -rf
DIR_DUP				=	mkdir -p ${@D}



all: ${NAME}

${NAME}: ${OBJS}
	${CC} $^ ${LIBFLAGS} -o $@

${OBJ_DIR}/%.o: ${SRC_DIR}/%.c
	${DIR_DUP}
	${CC} ${CFLAGS} ${CPPFLAGS} -c -o $@ $<

clean:
	${RM} ${OBJ_DIR}

fclean: clean
	${RM} ${NAME}
	${RM} .${NAME}_history

re: fclean
	${MAKE} all
