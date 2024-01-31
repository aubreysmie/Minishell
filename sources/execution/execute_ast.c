/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_ast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 07:18:06 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/31 21:22:33 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	execute_and_or_sub_tree(t_ast ast, t_session *session)
{
	if (ast->type == OR_IF_NODE)
	{
		if (!execute_ast(ast->left_child, session))
			return (0);
		if (session->last_cmd_status)
			if (!execute_ast(ast->right_child, session))
				return (0);
		return (1);
	}
	if (ast->type == AND_IF_NODE)
	{
		if (!execute_ast(ast->left_child, session))
			return (0);
		if (!session->last_cmd_status)
			if (!execute_ast(ast->right_child, session))
				return (0);
		return (1);
	}
	return (1);
}

bool	execute_ast(t_ast ast, t_session *session)
{
	if (g_signum != -1)
		return (1);
	if (ast->type == OR_IF_NODE || ast->type == AND_IF_NODE)
	{
		if (!execute_and_or_sub_tree(ast, session))
			return (0);
	}
	else if (ast->type == PIPE_NODE)
	{	
		if (!execute_pipe_sub_tree(ast, session))
			return (0);
	}
	else if (ast->type == CMD_NODE)
	{
		if (!execute_cmd_node(&ast->cmd, session))
			return (0);
	}
	return (1);
}
