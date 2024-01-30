/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_cmd_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 05:50:50 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/30 07:04:01 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**get_expanded_stra(char *str, t_session *session, bool should_split)
{
	char	**expanded_stra;
	char	*expanded_str;
	char	*temp;

	expanded_str = expand_parameters(str, session);
	if (!expanded_str)
		return (NULL);
	temp = expanded_str;
	expanded_str = match_patterns(expanded_str);
	free(temp);
	if (!expanded_str)
		return (NULL);
	temp = expanded_str;
	expanded_str = remove_quotes(expanded_str);
	free(temp);
	if (!expanded_str)
		return (NULL);
	if (!should_split)
	{
		expanded_stra = NULL;
		ft_straadd(&expanded_stra, expanded_str);
		return (expanded_stra);
	}
	expanded_stra = ft_splitset(expanded_str, " \n\t");
	return (free(expanded_str), expanded_stra);
}

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
	bool	should_split;

	expanded_cmd_current_arg = get_expanded_stra(cmd->cmd_name, session, true);
	expanded_cmd_args = NULL;
	should_split = !ft_strareeq(cmd->cmd_name, "export");
	cmd->cmd_name = expanded_cmd_current_arg[0];
	if (!add_expanded_arg(expanded_cmd_current_arg, &expanded_cmd_args))
		return (0);
	i = 1;
	while (cmd->cmd_args[i])
	{
		expanded_cmd_current_arg = get_expanded_stra(cmd->cmd_args[i],
				session, should_split);
		if (!add_expanded_arg(expanded_cmd_current_arg, &expanded_cmd_args))
			return (0);
		i++;
	}
	ft_strafree(cmd->cmd_args);
	cmd->cmd_args = expanded_cmd_args;
	return (1);
}
