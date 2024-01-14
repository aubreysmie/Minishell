/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_heredocs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 04:29:52 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/14 06:19:02 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	get_delimiter(t_delimiter *delimiter, t_token_queue **delimiter_queue)
{
	t_lstr	delimiter_lstr;

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
	delimiter->str = remove_quotes(
			ft_substrrange(delimiter_lstr.str, 0, delimiter_lstr.len - 1));
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

bool	update_heredoc(char **heredoc, char *line)
{
	char	*temp;

	if (!(*heredoc))
	{
		*heredoc = ft_strdup("");
		return (*heredoc);
	}
	temp = *heredoc;
	*heredoc = ft_strjoin(*heredoc, line);
	free(temp);
	if (!(*heredoc))
		return (0);
	temp = *heredoc;
	*heredoc = ft_strjoin(*heredoc, "\n");
	free(temp);
	return (*heredoc);
}

bool	get_heredoc(t_cstr *input, char *delimiter, char **heredoc)
{
	char	*line;

	line = NULL;
	*heredoc = NULL;
	if (input->str[input->cursor])
		input->cursor--;
	while (!ft_strareeq(line, delimiter))
	{
		if (!input->str[input->cursor])
			if (!update_input(input))
				return (0);
		input->cursor++;
		if (!update_heredoc(heredoc, line))
			return (free(line), 0);
		free(line);
		line = ft_substrrange(input->str, input->cursor, input->cursor
				+ ft_strchrseti(input->str + input->cursor, "\n\0") - 1);
		if (!line)
			return (free(*heredoc), 0);
		input->cursor = input->cursor + ft_strlen(line);
	}
	free(line);
	return (1);
}

bool	generate_heredocs(t_cstr *input,
			t_token_queue **delimiter_queue, t_token_queue **heredoc_queue)
{
	t_delimiter	delimiter;
	char		*heredoc;

	while (*delimiter_queue)
	{
		if (!get_delimiter(&delimiter, delimiter_queue))
			return (0);
		if (!get_heredoc(input, delimiter.str, &heredoc))
			return (free(delimiter.str), 0);
		if (!fix_heredoc(&heredoc, delimiter.was_quoted))
			return (free(delimiter.str), 0);
		if (!add_token_to_queue(heredoc_queue,
				(t_token){WORD_TOKEN, (t_lstr){heredoc, ft_strlen(heredoc)}}))
			return (free(delimiter.str), free(heredoc), 0);
		free(delimiter.str);
	}
	return (1);
}
