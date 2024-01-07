/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_session.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:37:30 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/07 19:41:11 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "session.h"

static bool	restore_hist(void)
{
	int		fd;
	char	*line;

	fd = open(".minishell_history", O_RDONLY);
	if (fd == -1)
		return (1);
	if (!get_next_line(&line, fd))
		return (0);
	while (line)
	{
		line[ft_strlen(line) - 1] = 0;
		add_history(line);
		free(line);
		if (!get_next_line(&line, fd))
			return (0);
	}
	free(line);
	return (1);
}

bool	init_session(t_session *session, char **envp)
{
	if (!restore_hist())
		return (0);
	session->env = envp;
	session->history = NULL;
	session->last_cmd_status = 0;
	session->should_exit = false;
	return (1);
}
