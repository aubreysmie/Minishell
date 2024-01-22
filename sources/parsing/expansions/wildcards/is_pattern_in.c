/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_pattern_in.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 23:43:32 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/20 23:44:19 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	has_pattern(t_lstr pattern, t_lstr candidate,
			unsigned int *pattern_len_p)
{
	t_quotes				quotes;
	unsigned int			i;
	unsigned int			j;

	quotes = (t_quotes){false, 0};
	i = 0;
	j = 0;
	while (i < pattern.len)
	{
		if (!quotes.is_in && ft_charisinset(pattern.str[i], "'\""))
			quotes = (t_quotes){true, pattern.str[i]};
		else if (pattern.str[i] == quotes.type)
			quotes = (t_quotes){false, 0};
		else
		{
			if (pattern.str[i] != candidate.str[j])
				return (false);
			j++;
		}
		i++;
	}
	*pattern_len_p = j;
	return (true);
}

bool	is_pattern_in(char *matching_leftover_str,
			int pattern_start, int pattern_end, t_lstr *available_file)
{
	t_lstr					pattern;
	unsigned int			pattern_len;
	unsigned int			j;

	if (pattern_start > pattern_end)
		return (true);
	pattern = (t_lstr){matching_leftover_str + pattern_start,
		pattern_end - pattern_start + 1};
	pattern_len = 0;
	j = 0;
	while (j < available_file->len)
	{
		if (has_pattern(pattern,
				(t_lstr){available_file->str + j, available_file->len},
			&pattern_len))
		{
			available_file->str += j + pattern_len;
			return (true);
		}
		j++;
	}
	return (false);
}
