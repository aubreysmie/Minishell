/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_io.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 20:51:42 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/31 09:20:58 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	change_piped_io(t_io_fd io_fd,
			t_redir *input_redir, t_redir *output_redir)
{
	if (io_fd.rd_end != STDIN_FILENO)
	{
		if (input_redir->type == (enum e_redir_type)(-1))
		{
			if (dup2(io_fd.rd_end, STDIN_FILENO) == -1)
			{
				close(io_fd.rd_end);
				return (0);
			}
		}
		close(io_fd.rd_end);
	}
	if (io_fd.wr_end != STDOUT_FILENO)
	{
		if (output_redir->type == (enum e_redir_type)(-1))
		{
			if (dup2(io_fd.wr_end, STDOUT_FILENO) == -1)
			{
				close(io_fd.wr_end);
				return (0);
			}
		}
		close(io_fd.wr_end);
	}
	return (1);
}

bool	change_input_heredoc(char *heredoc,
			t_io_fd *std_io_save_p, t_session *session)
{
	int	pipefd[2];
	int	cpid;

	if (pipe(pipefd) == -1)
		return (0);
	cpid = fork();
	if (cpid == -1)
		return (0);
	if (cpid == 0)
	{
		restore_std_io(std_io_save_p);
		if (!write_heredoc_in_pipe(pipefd, heredoc))
			destroy_and_exit(EXIT_FAILURE, session);
		destroy_and_exit(EXIT_SUCCESS, session);
	}
	close(pipefd[1]);
	if (dup2(pipefd[0], STDIN_FILENO) == -1)
	{
		close(pipefd[0]);
		return (0);
	}
	close(pipefd[0]);
	return (1);
}

bool	change_input(t_redir *input_redir, int *last_cmd_status_p)
{
	int	rd_end;

	if (input_redir->type == (enum e_redir_type)(-1))
		return (1);
	open_input_file(&rd_end, input_redir);
	if (rd_end == -2)
		return (1);
	if (rd_end == -1)
	{
		*last_cmd_status_p = errno;
		disp_access_error(input_redir->file, NULL, strerror(errno));
		return (1);
	}
	if (dup2(rd_end, STDIN_FILENO) == -1)
	{
		close(rd_end);
		return (0);
	}
	close(rd_end);
	return (1);
}

bool	change_output(t_redir *output_redir, int *last_cmd_status_p)
{
	int	wr_end;

	if (output_redir->type == (enum e_redir_type)(-1))
		return (1);
	open_output_file(&wr_end, output_redir);
	if (wr_end == -1)
	{
		*last_cmd_status_p = errno;
		disp_access_error(output_redir->file, NULL, strerror(errno));
		return (1);
	}
	if (dup2(wr_end, STDOUT_FILENO) == -1)
	{
		close(wr_end);
		return (0);
	}
	close(wr_end);
	return (1);
}

bool	change_io(t_redir *input_redir, t_redir *output_redir,
			int *last_cmd_status_p)
{
	if (!change_input(input_redir, last_cmd_status_p))
		return (0);
	if (*last_cmd_status_p)
		return (1);
	if (!change_output(output_redir, last_cmd_status_p))
		return (0);
	return (1);
}
