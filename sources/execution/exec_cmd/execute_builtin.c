/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 20:36:53 by ekhaled           #+#    #+#             */
/*   Updated: 2024/02/04 19:31:59 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	execute_builtin(t_cmd *cmd, t_session *session)
{
	t_io_fd	std_io_save;

	if (!save_std_io(&std_io_save))
		return (0);
	if (!change_io(&cmd->input_redir, &cmd->output_redir,
			&session->last_cmd_status))
		return (restore_std_io(&std_io_save), 0);
	if (session->last_cmd_status)
		return (restore_std_io(&std_io_save));
	if (cmd->input_redir.type == HEREDOC_REDIR)
		if (!change_input_heredoc(cmd->input_redir.heredoc,
				&std_io_save, session))
			return (restore_std_io(&std_io_save), 0);
	if (ft_strareeq(cmd->cmd_name, "exit"))
		if (!restore_std_io(&std_io_save))
			return (0);
	call_builtin(cmd->cmd_name, cmd->cmd_args, session);
	if (session->last_cmd_status < 0)
		return (restore_std_io(&std_io_save), 0);
	wait(NULL);
	return (restore_std_io(&std_io_save));
}
