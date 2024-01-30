/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_cmd_words.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 04:59:16 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/30 23:23:17 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	expand_heredoc(t_redir *input_redir, t_session *session)
{
	char	*expanded_heredoc;

	expanded_heredoc = expand_parameters(input_redir->heredoc, session);
	if (!expanded_heredoc)
		return (0);
	free(input_redir->heredoc);
	input_redir->heredoc = ft_substrrange(
			expanded_heredoc, 1, ft_strlen(expanded_heredoc) - 2);
	free(expanded_heredoc);
	if (!input_redir->heredoc)
		return (0);
	return (1);
}

bool	check_expanded_redir(t_redir *redir, t_session *session,
			int *new_exit_status_p)
{
	char	*temp;

	temp = redir->file;
	redir->file = expand_parameters(temp, session);
	free(temp);
	if (!redir->file)
		return (0);
	temp = redir->file;
	redir->file = remove_quotes(temp);
	free(temp);
	if (!redir->file)
		return (0);
	if (ft_charisinset(' ', redir->file)
		|| ft_strlen(redir->file) == 0)
	{
		disp_access_error(redir->file, NULL, "ambiguous redirect");
		*new_exit_status_p = 1;
	}
	return (1);
}

bool	expand_redirs(t_cmd *cmd, t_session *session)
{
	int	new_exit_status;

	new_exit_status = 0;
	if (cmd->input_redir.type == HEREDOC_REDIR)
	{
		if (!expand_heredoc(&cmd->input_redir, session))
			return (0);
	}
	else if (cmd->input_redir.type != (enum e_redir_type)(-1))
		if (!check_expanded_redir(&cmd->input_redir, session,
				&new_exit_status))
			return (0);
	if (cmd->output_redir.type != (enum e_redir_type)(-1))
		if (!check_expanded_redir(&cmd->output_redir, session,
				&new_exit_status))
			return (0);
	session->last_cmd_status = new_exit_status;
	return (1);
}

bool	expand_cmd_words(t_cmd *cmd, t_session *session)
{
	if (cmd->cmd_name)
		if (!expand_cmd_args(cmd, session))
			return (0);
	if (!expand_redirs(cmd, session))
		return (0);
	return (1);
}
