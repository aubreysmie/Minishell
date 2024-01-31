/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 00:58:27 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/31 11:08:08 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include <unistd.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>

# include "session.h"
# include "parsing.h"

typedef struct s_io_fd
{
	int	rd_end;
	int	wr_end;
}	t_io_fd;

bool	execute_ast(t_ast ast, t_session *session);

bool	execute_cmd_node(t_cmd *cmd, t_session *session);
bool	execute_builtin(t_cmd *cmd, t_session *session);
bool	execute_cmd(t_cmd *cmd, t_session *session);

bool	execute_pipe_sub_tree(t_ast ast, t_session *session);
bool	execute_piped_cmd_node(t_cmd *cmd, t_session *session,
			t_io_fd io_fd, int fd_to_close);
bool	execute_last_piped_cmd_node(t_cmd *cmd, t_session *session,
			t_io_fd io_fd, int *cpid_p);
bool	execute_piped_builtin(t_io_fd io_fd, t_cmd *cmd,
			t_session *session, int fd_to_close);
bool	execute_last_piped_builtin(t_io_fd io_fd, t_cmd *cmd,
			t_session *session, int *cpid_p);
bool	execute_piped_cmd(t_io_fd io_fd, t_cmd *cmd,
			t_session *session, int fd_to_close);
bool	execute_last_piped_cmd(t_io_fd io_fd, t_cmd *cmd,
			t_session *session, int *cpid_p);

bool	call_cmd(char *cmd_name, char **cmd_args, char **env,
			int *last_cmd_status_p);
void	call_builtin(char *cmd_name, char **cmd_args, t_session *session);

bool	check_if_dir(char *name, bool *is_dir_p);

bool	change_io(t_redir *input_redir, t_redir *output_redir,
			int *last_cmd_status_p);
bool	change_input_heredoc(char *heredoc,
			t_io_fd *std_io_save_p, t_session *session);
bool	change_piped_io(t_io_fd io_fd,
			t_redir *input_redir, t_redir *output_redir);

void	open_input_file(int *rd_end, t_redir *input_redir);
void	open_output_file(int *wr_end, t_redir *output_redir);

bool	expand_cmd_words(t_cmd *cmd, t_session *session);
bool	expand_cmd_args(t_cmd *cmd, t_session *session);

int		get_last_cmd_exit_status(int cpid);

bool	is_cmd_builtin(char *cmd_name);

bool	save_std_io(t_io_fd *std_io_save);
bool	restore_std_io(t_io_fd *std_io_save);

void	destroy_and_exit(int exit_status, t_session *session);

bool	write_heredoc_in_pipe(int pipefd[2], char *heredoc);

#endif
