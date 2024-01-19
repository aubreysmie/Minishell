/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_redirs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 05:59:47 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/19 20:15:04 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	update_redir_types(t_token token, t_cmd *cmd,
			enum e_redir_type *redir_type)
{
	if (token.type == LESS_TOKEN)
	{
		cmd->input_redir.type = INPUT_REDIR;
		*redir_type = INPUT_REDIR;
	}
	if (token.type == DLESS_TOKEN)
	{
		cmd->input_redir.type = HEREDOC_REDIR;
		*redir_type = HEREDOC_REDIR;
	}
	if (token.type == GREAT_TOKEN)
	{
		cmd->output_redir.type = OUTPUT_REDIR;
		*redir_type = OUTPUT_REDIR;
	}
	if (token.type == DGREAT_TOKEN)
	{
		cmd->output_redir.type = OUTPUT_APPEND_REDIR;
		*redir_type = OUTPUT_APPEND_REDIR;
	}
}

bool	update_redir_files(t_token token, t_token_queue **heredoc_queue,
			t_cmd *cmd, enum e_redir_type redir_type)
{
	if (redir_type == OUTPUT_REDIR || redir_type == OUTPUT_APPEND_REDIR)
	{
		if (cmd->output_redir.file)
			free(cmd->output_redir.file);
		cmd->output_redir.file = ft_substrrange(
				token.content.str, 0, ft_max(0, token.content.len - 1));
		if (!cmd->output_redir.file)
			return (0);
		return (1);
	}
	if (redir_type == INPUT_REDIR)
	{
		if (cmd->input_redir.file)
			free(cmd->input_redir.file);
		cmd->input_redir.file = ft_substrrange(
				token.content.str, 0, ft_max(0, token.content.len - 1));
		if (!cmd->input_redir.file)
			return (0);
		return (1);
	}
	if (cmd->input_redir.heredoc)
		free(cmd->input_redir.heredoc);
	cmd->input_redir.heredoc = (*heredoc_queue)->token.content.str;
	free(ft_queuepop(heredoc_queue));
	return (1);
}

bool	try_to_update_redir_files(t_token_queue *token_el,
			t_token_queue **heredoc_queue,
				t_node **leaf, enum e_redir_type *redir_type)
{
	if (token_el->token.type != WORD_TOKEN)
	{
		disp_token_error(token_el->token.type);
		free_cmd(&(*leaf)->cmd);
		free(*leaf);
		*leaf = NULL;
		return (1);
	}
	if (!update_redir_files(token_el->token, heredoc_queue,
			&(*leaf)->cmd, *redir_type))
		return (0);
	*redir_type = -1;
	return (1);
}
