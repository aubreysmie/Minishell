/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:21:27 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/30 07:37:11 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_operator_delimited(unsigned int *i, t_cstr *input)
{
	if (is_operator((t_lstr){input->str + input->cursor, *i + 1}))
	{
		(*i)++;
		return (0);
	}
	return (1);
}

void	update_quoting_with_incr(t_quotes *quotes,
				unsigned int *i, t_cstr *input)
{
	if (!quotes->is_in)
		*quotes = (t_quotes){true, input->str[input->cursor + *i]};
	else if (input->str[input->cursor + *i] == quotes->type)
		*quotes = (t_quotes){false, 0};
	(*i)++;
}

bool	is_delimited_by_operator(unsigned int *i, t_cstr *input)
{
	if ((input->str[input->cursor + *i] == '&'
			&& input->str[input->cursor + *i + 1] != '&'))
	{
		(*i)++;
		return (0);
	}
	if (*i)
		return (1);
	(*i)++;
	return (0);
}

bool	is_newline_or_word_delimited(unsigned int *i, t_cstr *input)
{
	if ((*i == 1) && input->str[input->cursor + *i - 1] == '\n')
		return (1);
	if ((*i == 0) && input->str[input->cursor + *i] == '\n')
	{
		(*i)++;
		return (0);
	}
	if (ft_charisinset(input->str[input->cursor + *i], "\t \n"))
		return (1);
	else
	{
		(*i)++;
		return (0);
	}
}

t_lstr	get_token(t_quotes *quotes, unsigned int *i, t_cstr *input)
{
	while (input->str[input->cursor + *i])
	{
		if (!quotes->is_in
			&& is_operator((t_lstr){input->str + input->cursor, *i}))
		{
			if (is_operator_delimited(i, input))
				return ((t_lstr){input->str + input->cursor, *i});
		}
		else if (ft_charisinset(input->str[input->cursor + *i], "'\""))
			update_quoting_with_incr(quotes, i, input);
		else if (!quotes->is_in
			&& (ft_charisinset(input->str[input->cursor + *i], ")>&<(|")))
		{
			if (is_delimited_by_operator(i, input))
				return ((t_lstr){input->str + input->cursor, *i});
		}
		else if (!quotes->is_in)
		{
			if (is_newline_or_word_delimited(i, input))
				return ((t_lstr){input->str + input->cursor, *i});
		}
		else
			(*i)++;
	}
	return ((t_lstr){input->str + input->cursor, *i});
}
