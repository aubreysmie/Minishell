/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   session.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 20:53:10 by ekhaled           #+#    #+#             */
/*   Updated: 2023/12/29 02:50:17 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SESSION_H
# define SESSION_H

# include <stdbool.h>
# include <stdint.h>
# include <stdlib.h>

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_session
{
	char		**env;
	char		**history;
	uint8_t		last_cmd_status;
	bool		should_exit;
}	t_session;

bool	init_session(t_session *session, char **envp);
bool	destroy_session(t_session *session);

bool	get_next_line(char **line, int fd);

#endif