/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 01:49:43 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/19 20:17:57 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	update_cmd_args(t_token token, t_cmd *cmd)
{
	char	*new_cmd_arg;

	new_cmd_arg = ft_substrrange(token.content.str, 0,
			ft_max(0, token.content.len - 1));
	if (!new_cmd_arg)
		return (0);
	if (!cmd->cmd_name)
		cmd->cmd_name = new_cmd_arg;
	if (!ft_straadd(&cmd->cmd_args, new_cmd_arg))
	{
		free(new_cmd_arg);
		return (0);
	}
	return (1);
}

bool	update_cmd(t_token_queue **token_queue, t_token_queue **heredoc_queue,
			t_node **leaf, enum e_redir_type *redir_type)
{
	t_token_queue				*token_el;

	token_el = ft_queuepop(token_queue);
	if (*redir_type != ((enum e_redir_type)(-1)))
	{
		if (!try_to_update_redir_files(token_el, heredoc_queue,
				leaf, redir_type))
		{
			free(token_el);
			return (0);
		}
	}
	else if (token_el->token.type != WORD_TOKEN)
		update_redir_types(token_el->token, &(*leaf)->cmd, redir_type);
	else if (!update_cmd_args(token_el->token, &(*leaf)->cmd))
	{
		free(token_el);
		return (0);
	}
	free(token_el);
	return (1);
}
