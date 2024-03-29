/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd_node.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 19:58:22 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/30 08:32:00 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	execute_cmd_node(t_cmd *cmd, t_session *session)
{
	if (!expand_cmd_words(cmd, session))
		return (0);
	if (session->last_cmd_status)
		return (1);
	if (is_cmd_builtin(cmd->cmd_name))
	{
		if (!execute_builtin(cmd, session))
			return (0);
	}
	else
	{
		if (!execute_cmd(cmd, session))
			return (0);
	}
	return (1);
}
