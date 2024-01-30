/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_heredoc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 01:21:01 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/30 01:21:14 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

bool	update_input_str(t_cstr *input, bool *is_eof_p, char *delimiter)
{
	char	*old_input_str;

	old_input_str = input->str;
	if (!input->str[input->cursor])
	{
		if (!update_input(input))
			return (0);
		if (input->str == old_input_str)
		{
			disp_eof_warning(delimiter);
			*is_eof_p = true;
		}
	}
	if (!(*is_eof_p))
		input->cursor++;
	return (1);
}

bool	get_heredoc(t_cstr *input, char *delimiter, char **heredoc)
{
	char	*line;
	bool	is_eof;

	*heredoc = NULL;
	line = NULL;
	is_eof = false;
	if (input->str[input->cursor - 1] == '\n')
		input->cursor--;
	while (!ft_strareeq(line, delimiter))
	{
		if (!update_input_str(input, &is_eof, delimiter))
			return (0);
		if (!update_heredoc(heredoc, line))
			return (free(line), 0);
		if (is_eof)
			break ;
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
