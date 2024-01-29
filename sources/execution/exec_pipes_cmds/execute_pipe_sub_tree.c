/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipe_sub_tree.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 07:36:32 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/29 10:20:10 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_node	*get_leftmost_leaf(t_ast ast)
{
	t_node	*node;

	node = ast;
	while (node->left_child)
		node = node->left_child;
	return (node);
}

bool	execute_pipe_loop(t_node *node, t_session *session,
	int pipefd[2])
{
	int	temp_pipefd[2];

	if (pipe(temp_pipefd) == -1)
	{
		close(pipefd[0]);
		return (0);
	}
	if (!execute_piped_cmd_node(&node->right_child->cmd, session,
			(t_io_fd){pipefd[0], temp_pipefd[1]}, temp_pipefd[0]))
	{
		close(pipefd[0]);
		close(temp_pipefd[1]);
		return (0);
	}
	close(pipefd[0]);
	close(temp_pipefd[1]);
	pipefd[0] = temp_pipefd[0];
	pipefd[1] = temp_pipefd[1];
	return (1);
}

bool	execute_pipe_sub_tree(t_ast ast, t_session *session)
{
	t_node	*node;
	int		pipefd[2];
	int		cpid;

	node = get_leftmost_leaf(ast);
	if (pipe(pipefd) == -1)
		return (0);
	if (!execute_piped_cmd_node(&node->cmd, session,
			(t_io_fd){STDIN_FILENO, pipefd[1]}, pipefd[0]))
		return (close(pipefd[0]), close(pipefd[1]), 0);
	close(pipefd[1]);
	node = node->parent;
	while (node->parent && node->parent->type == PIPE_NODE)
	{
		if (!execute_pipe_loop(node, session, pipefd))
			return (0);
		node = node->parent;
	}
	if (!execute_last_piped_cmd_node(&node->right_child->cmd, session,
			(t_io_fd){pipefd[0], STDOUT_FILENO}, &cpid))
		return (close(pipefd[0]), 0);
	close(pipefd[0]);
	session->last_cmd_status = get_last_cmd_exit_status(cpid);
	return (1);
}
