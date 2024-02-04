/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 22:50:17 by ekhaled           #+#    #+#             */
/*   Updated: 2024/02/04 19:56:15 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_cmd_child(t_cmd *cmd, t_session *session)
{
	if (!change_io(&cmd->input_redir, &cmd->output_redir,
			&session->last_cmd_status))
		destroy_and_exit(EXIT_FAILURE, session);
	if (session->last_cmd_status)
		destroy_and_exit(session->last_cmd_status, session);
	if (!call_cmd(cmd->cmd_name, cmd->cmd_args,
			session->env, &session->last_cmd_status))
		destroy_and_exit(EXIT_FAILURE, session);
	destroy_and_exit(session->last_cmd_status, session);
}

bool	execute_cmd(t_cmd *cmd, t_session *session)
{
	int			cpid;
	t_io_fd		std_io_save;

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
		close(std_io_save.rd_end);
		close(std_io_save.wr_end);
		execute_cmd_child(cmd, session);
	}
	session->last_cmd_status = get_last_cmd_exit_status(cpid);
	if (!restore_std_io(&std_io_save))
		return (0);
	return (1);
}
