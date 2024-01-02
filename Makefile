# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/27 21:02:35 by ekhaled           #+#    #+#              #
#    Updated: 2024/01/02 05:54:58 by ekhaled          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:=	minishell


SRC_DIR			:=	sources
OBJ_DIR			:=	objects

SRCS_UTILS		:=	ft_calloc.c \
					ft_stradup.c \
					ft_strafree.c \
					ft_stralen.c \
					ft_strchri.c \
					ft_strcpy.c \
					ft_strdup.c \
					ft_strjoin.c \
					ft_strlen.c \
					ft_substrrange.c \
					get_next_line.c
SRCS_SESSION	:=	init_session.c \
					destroy_session.c
SRCS_MAIN		:=	main.c
SRCS			:=	${addprefix utils/, ${SRCS_UTILS}} \
					${addprefix session/, ${SRCS_SESSION}} \
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
