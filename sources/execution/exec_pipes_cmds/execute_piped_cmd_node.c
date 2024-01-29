/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_piped_cmd_node.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 10:51:04 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/29 10:21:06 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	execute_last_piped_cmd_node(t_cmd *cmd, t_session *session,
			t_io_fd io_fd, int *cpid_p)
{
	// if (!expand_cmd_words(cmd))
	// 	return (0);
	if (is_cmd_builtin(cmd->cmd_name))
	{
		if (!execute_last_piped_builtin(io_fd, cmd, session, cpid_p))
			return (0);
	}
	else
	{
		if (!execute_last_piped_cmd(io_fd, cmd, session, cpid_p))
			return (0);
	}
	return (1);
}

bool	execute_piped_cmd_node(t_cmd *cmd, t_session *session,
			t_io_fd io_fd, int fd_to_close)
{
	// if (!expand_cmd_words(cmd))
	// 	return (0);
	if (is_cmd_builtin(cmd->cmd_name))
	{
		if (!execute_piped_builtin(io_fd, cmd, session, fd_to_close))
			return (0);
	}
	else
	{
		if (!execute_piped_cmd(io_fd, cmd, session, fd_to_close))
			return (0);
	}
	return (1);
}
