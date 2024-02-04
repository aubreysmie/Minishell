/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_piped_builtin.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 08:35:41 by ekhaled           #+#    #+#             */
/*   Updated: 2024/02/04 19:56:24 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_piped_builtin_child(t_io_fd io_fd, t_cmd *cmd,
			t_session *session)
{
	if (!change_piped_io(io_fd, &cmd->input_redir, &cmd->output_redir))
		destroy_and_exit(EXIT_FAILURE, session);
	if (!change_io(&cmd->input_redir, &cmd->output_redir,
			&session->last_cmd_status))
		destroy_and_exit(EXIT_FAILURE, session);
	if (session->last_cmd_status)
		destroy_and_exit(session->last_cmd_status, session);
	call_builtin(cmd->cmd_name, cmd->cmd_args, session);
	if (session->last_cmd_status < 0)
		destroy_and_exit(EXIT_FAILURE, session);
	destroy_and_exit(session->last_cmd_status, session);
}

bool	execute_last_piped_builtin(t_io_fd io_fd, t_cmd *cmd,
			t_session *session, int *cpid_p)
{
	t_io_fd	std_io_save;

	if (!save_std_io(&std_io_save))
		return (0);
	if (cmd->input_redir.type == HEREDOC_REDIR)
		if (!change_input_heredoc(cmd->input_redir.heredoc,
				&std_io_save, session))
			return (restore_std_io(&std_io_save), 0);
	*cpid_p = fork();
	if (*cpid_p == -1)
		return (restore_std_io(&std_io_save), 0);
	if (*cpid_p == 0)
	{
		init_signals_child();
		close(std_io_save.rd_end);
		close(std_io_save.wr_end);
		execute_piped_builtin_child(io_fd, cmd, session);
	}
	if (!restore_std_io(&std_io_save))
		return (0);
	return (1);
}

bool	execute_piped_builtin(t_io_fd io_fd, t_cmd *cmd,
			t_session *session, int fd_to_close)
{
	t_io_fd	std_io_save;
	int		cpid;

	if (!save_std_io(&std_io_save))
		return (0);
	if (cmd->input_redir.type == HEREDOC_REDIR)
		if (!change_input_heredoc(cmd->input_redir.heredoc,
				&std_io_save, session))
			return (restore_std_io(&std_io_save), 0);
	cpid = fork();
	if (cpid == -1)
		return (restore_std_io(&std_io_save), 0);
	if (cpid == 0)
	{
		init_signals_child();
		close(fd_to_close);
		close(std_io_save.rd_end);
		close(std_io_save.wr_end);
		execute_piped_builtin_child(io_fd, cmd, session);
	}
	if (!restore_std_io(&std_io_save))
		return (0);
	return (1);
}
