# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/27 21:02:35 by ekhaled           #+#    #+#              #
#    Updated: 2024/01/16 01:40:50 by ekhaled          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:=	minishell


SRC_DIR			:=	sources
OBJ_DIR			:=	objects

SRCS_UTILS		:=	ft_calloc.c \
					ft_charisinset.c \
					ft_charsetisinlstr.c \
					ft_isalnum.c \
					ft_isalpha.c \
					ft_isdigit.c \
					ft_lstrchrseti.c \
					ft_lstrcmp.c \
					ft_max.c \
					ft_split.c \
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
					ft_strjoin.c \
					ft_strjoinfree.c \
					ft_strlen.c \
					ft_substrrange.c \
					ft_uitoa.c \
					get_next_line.c
SRCS_BUILTINS	:=	env.c \
					export.c \
					pwd.c \
					unset.c
SRCS_ERRORS		:=	error_disp.c
SRCS_EXPANSION	:=	remove_quotes.c
SRCS_QUEUE		:=	ft_queuefree.c \
					ft_queuefreeall.c \
					ft_queuelast.c \
					ft_queuelen.c \
					ft_queuenew.c \
					ft_queuepop.c \
					ft_queuepush.c
SRCS_TOKEN_REC	:=	is_name.c \
					is_operator.c \
					is_word.c
SRCS_TOKENIZER	:=	${addprefix queue/, ${SRCS_QUEUE}} \
					${addprefix token_recognition/, ${SRCS_TOKEN_REC}} \
					generate_heredocs.c \
					generate_ordinary_tokens.c \
					generate_tokens.c \
					get_token.c \
					lstr_to_token.c
SRCS_PARSING	:=	${addprefix expansions/, ${SRCS_EXPANSION}} \
					${addprefix tokenizer/, ${SRCS_TOKENIZER}} \
					read_input.c \
					update_input.c
SRCS_SESSION	:=	init_session.c \
					destroy_session.c
SRCS_MAIN		:=	main.c
SRCS			:=	${addprefix builtins/, ${SRCS_BUILTINS}} \
					${addprefix errors/, ${SRCS_ERRORS}} \
					${addprefix parsing/, ${SRCS_PARSING}} \
					${addprefix session/, ${SRCS_SESSION}} \
					${addprefix utils/, ${SRCS_UTILS}} \
					${SRCS_MAIN}

SRCS			:=	${SRCS:%=${SRC_DIR}/%}
OBJS			:=	${SRCS:${SRC_DIR}/%.c=${OBJ_DIR}/%.o}

LIBFLAGS		:=	-lreadline
CFLAGS			:=	-Wall -Wextra -Werror
CPPFLAGS		:=	-I includes

RM				:=	${RM} -rf
DIR_DUP			=	mkdir -p ${@D}

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
