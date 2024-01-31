/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   session.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 20:53:10 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/31 11:42:50 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SESSION_H
# define SESSION_H

# include <unistd.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdlib.h>

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

# include "utils.h"
# include "parsing.h"

typedef struct s_cmd_info
{
	t_cstr			input;
	t_token_queue	*token_queue;
	t_token_queue	*heredoc_queue;
	t_ast			ast;
}	t_cmd_info;

typedef struct s_session
{
	char		**env;
	char		**history;
	t_cmd_info	cmd_info;
	int			last_cmd_status;
}	t_session;

bool	init_session(t_session *session, char **envp);
void	destroy_session(t_session *session);

void	add_history_to_histfile(char **history);

#endif