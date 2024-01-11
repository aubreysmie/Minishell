/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delimit_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:21:27 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/11 13:26:49 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lstr	get_token_lstr(t_quotes *quotes, unsigned int *i, t_cstr *input)
{
	while (input->str[input->cursor + *i])
	{
		if (input->cursor && !quotes->in && is_operator((t_lstr){input->str + input->cursor, *i + 1}))
			(*i)++;
		else if (input->cursor && is_operator((t_lstr){input->str + input->cursor, *i})
			&& !quotes->in && !is_operator((t_lstr){input->str + input->cursor, *i + 1}))
			return ((t_lstr){input->str + input->cursor, *i});
		else if (ft_charisin(input->str[input->cursor + *i], "'\"") && !quotes->in)
			*quotes = (t_quotes){true, input->str[input->cursor + (*i)++]};
		else if (ft_charisin(input->str[input->cursor + *i], "'\"") && input->str[input->cursor + *i] == quotes->type)
		{
			*quotes = (t_quotes){false, 0};
			(*i)++;
		}
		else if (!quotes->in && ft_charisin(input->str[input->cursor + *i], ")>&<(|"))
		{
			if (*i)
				return ((t_lstr){input->str + input->cursor, *i});
			(*i)++;
		}
		else if (!quotes->in && (*i == 1) && input->str[input->cursor + *i - 1] == '\n')
			return ((t_lstr){input->str + input->cursor, *i});
		else if (!quotes->in && (*i == 0) && input->str[input->cursor + *i] == '\n')
			(*i)++;
		else if (!quotes->in && ft_charisin(input->str[input->cursor + *i], "\t \n"))
			return ((t_lstr){input->str + input->cursor, *i});
		else
			(*i)++;
	}
	return ((t_lstr){input->str + input->cursor, *i});
}

bool	update_input(t_cstr *input)
{
	char	*og_input_str;
	char	*new_input_str;

	og_input_str = input->str;
	new_input_str = readline("> ");
	input->str = ft_strajoin((char *[]){og_input_str, "\n", new_input_str, NULL});
	free(og_input_str);
	free(new_input_str);
	if (!input->str)
		return (0);
	return (1);
}

bool	delimit_token(t_cstr *input, t_lstr *token_lstr)
{
	static t_quotes		quotes = (t_quotes){false, 0};
	static unsigned int	i = 0;

	*token_lstr = get_token_lstr(&quotes, &i, input);
	if (!quotes.in)
	{
		i = 0;
		return (1);
	}
	if (!update_input(input))
		return (0);
	return (delimit_token(input, token_lstr));
}
