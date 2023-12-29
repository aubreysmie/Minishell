/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_session.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:37:30 by ekhaled           #+#    #+#             */
/*   Updated: 2023/12/29 02:50:13 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "session.h"

bool	restore_hist(void)
{
	int		fd;
	char	*line;

	fd = open(".minishell_history", O_RDONLY | O_CREAT, 666);
	if (fd == -1)
		return (1);
	if (!get_next_line(&line, fd))
		return (0);
	while (line)
	{
		add_history(line);
		free(line);
		if (!get_next_line(&line, fd))
			return (false);
	}
	return (1);
}

bool	init_session(t_session *session, char **envp)
{
	if (!restore_hist())
		return (0);
	session->env = envp;
	session->last_cmd_status = 0;
	session->should_exit = false;
	return (1);
}
