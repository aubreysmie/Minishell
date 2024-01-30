/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_heredocs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 04:29:52 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/30 01:20:48 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	get_delimiter(t_delimiter *delimiter, t_token_queue **delimiter_queue)
{
	t_lstr	delimiter_lstr;
	char	*temp;

	delimiter_lstr = (*delimiter_queue)->token.content;
	free(ft_queuepop(delimiter_queue));
	if (!ft_charsetisinlstr("\'\"", delimiter_lstr))
	{
		delimiter->was_quoted = false;
		delimiter->str
			= ft_substrrange(delimiter_lstr.str, 0, delimiter_lstr.len - 1);
		return (delimiter->str);
	}
	delimiter->was_quoted = true;
	temp = ft_substrrange(delimiter_lstr.str, 0, delimiter_lstr.len - 1);
	delimiter->str = remove_quotes(temp);
	free(temp);
	return (delimiter->str);
}

bool	fix_heredoc(char **heredoc, bool was_delimiter_quoted)
{
	char	*temp;

	temp = *heredoc;
	if (was_delimiter_quoted)
		*heredoc = ft_strajoin((char *[]){"'", *heredoc, "'", NULL});
	else
		*heredoc = ft_strajoin((char *[]){"\"", *heredoc, "\"", NULL});
	free(temp);
	return (*heredoc);
}

bool	generate_heredocs(t_cstr *input, t_token_queue **token_queue,
			t_token_queue **delimiter_queue, t_token_queue **heredoc_queue)
{
	t_delimiter	delimiter;
	char		*heredoc;
	char		*old_input_str;

	while (*delimiter_queue)
	{
		old_input_str = input->str;
		if (!get_delimiter(&delimiter, delimiter_queue))
			return (0);
		if (!get_heredoc(input, delimiter.str, &heredoc))
			return (free(delimiter.str), 0);
		if (old_input_str != input->str)
			update_queues(old_input_str, input->str,
				*token_queue, *delimiter_queue);
		if (!fix_heredoc(&heredoc, delimiter.was_quoted))
			return (free(delimiter.str), 0);
		if (!add_token_to_queue(heredoc_queue,
				(t_token){WORD_TOKEN, (t_lstr){heredoc, ft_strlen(heredoc)}}))
			return (free(delimiter.str), free(heredoc), 0);
		free(delimiter.str);
	}
	return (1);
}
