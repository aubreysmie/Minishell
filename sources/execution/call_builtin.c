/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 08:32:32 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/29 11:40:22 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	call_builtin(char *cmd_name, char **cmd_args, t_session *session)
{
	if (ft_strareeq(cmd_name, "exit"))
		ft_exit(cmd_args, session);
	if (ft_strareeq(cmd_name, "export"))
		session->last_cmd_status = ft_export(cmd_args, &session->env);
	if (ft_strareeq(cmd_name, "env"))
		session->last_cmd_status = ft_env(cmd_args, &session->env);
	if (ft_strareeq(cmd_name, "unset"))
		session->last_cmd_status = ft_unset(cmd_args, &session->env);
	if (ft_strareeq(cmd_name, "cd"))
		session->last_cmd_status = ft_cd(cmd_args, &session->env);
	if (ft_strareeq(cmd_name, "echo"))
		session->last_cmd_status = ft_echo(cmd_args);
	if (ft_strareeq(cmd_name, "pwd"))
		session->last_cmd_status = ft_pwd();
}
