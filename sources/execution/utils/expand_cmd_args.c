/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_cmd_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 05:50:50 by ekhaled           #+#    #+#             */
/*   Updated: 2024/02/01 17:09:51 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	add_expanded_arg(char **expanded_cmd_current_arg,
			char ***expanded_cmd_args_p)
{
	int	i;

	i = 0;
	while (expanded_cmd_current_arg[i])
	{
		if (!ft_straadd(expanded_cmd_args_p, expanded_cmd_current_arg[i]))
			return (ft_strafree(*expanded_cmd_args_p),
				ft_strafree(expanded_cmd_current_arg), 0);
		i++;
	}
	free(expanded_cmd_current_arg);
	return (1);
}

bool	expand_cmd_args(t_cmd *cmd, t_session *session)
{
	char	**expanded_cmd_current_arg;
	char	**expanded_cmd_args;
	int		i;

	expanded_cmd_current_arg = apply_expansions(cmd->cmd_name, session);
	expanded_cmd_args = NULL;
	cmd->cmd_name = expanded_cmd_current_arg[0];
	if (!add_expanded_arg(expanded_cmd_current_arg, &expanded_cmd_args))
		return (0);
	i = 1;
	while (cmd->cmd_args[i])
	{
		expanded_cmd_current_arg = apply_expansions(cmd->cmd_args[i],
				session);
		if (!add_expanded_arg(expanded_cmd_current_arg, &expanded_cmd_args))
			return (0);
		i++;
	}
	ft_strafree(cmd->cmd_args);
	cmd->cmd_args = expanded_cmd_args;
	return (1);
}
