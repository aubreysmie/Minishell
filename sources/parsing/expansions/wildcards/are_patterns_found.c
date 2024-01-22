/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   are_patterns_found.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 02:57:24 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/21 00:03:57 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_last_pattern_found(char *str, char *file,
			int last_asterisk_index, int *available_file_end_p)
{
	t_quotes	quotes;
	int			i;
	int			j;

	quotes = (t_quotes){false, 0};
	i = ft_max(0, ft_strlen(str) - 1);
	j = ft_max(0, ft_strlen(file) - 1);
	while (i != last_asterisk_index)
	{
		if (!quotes.is_in && ft_charisinset(str[i], "'\""))
			quotes = (t_quotes){true, str[i]};
		else if (str[i] == quotes.type)
			quotes = (t_quotes){false, 0};
		else
		{
			if (str[i] != file[j])
				return (false);
			j--;
		}
		i--;
	}
	*available_file_end_p = j;
	return (true);
}

bool	is_first_pattern_found(char *str, char *file,
			int first_asterisk_index, int *available_file_start_p)
{
	t_quotes	quotes;
	int			i;
	int			j;

	quotes = (t_quotes){false, 0};
	i = 0;
	j = 0;
	while (i != first_asterisk_index)
	{
		if (!quotes.is_in && ft_charisinset(str[i], "'\""))
			quotes = (t_quotes){true, str[i]};
		else if (str[i] == quotes.type)
			quotes = (t_quotes){false, 0};
		else
		{
			if (str[i] != file[j])
				return (false);
			j++;
		}
		i++;
	}
	*available_file_start_p = j;
	return (true);
}

bool	are_middle_patterns_found(t_lstr *available_file,
			t_lstr matching_leftover)
{
	t_quotes		quotes;
	unsigned int	i;
	unsigned int	pattern_start;
	unsigned int	pattern_end;

	quotes = (t_quotes){false, 0};
	i = 1;
	pattern_start = 1;
	while (i < matching_leftover.len - 1)
	{
		update_quoting(&quotes, matching_leftover.str, i);
		if (!quotes.is_in && matching_leftover.str[i] == '*')
		{
			pattern_end = i - 1;
			if (!is_pattern_in(matching_leftover.str,
					pattern_start, pattern_end, available_file))
				return (false);
			pattern_start = i + 1;
		}
		i++;
	}
	pattern_end = matching_leftover.len - 2;
	return (is_pattern_in(matching_leftover.str,
			pattern_start, pattern_end, available_file));
}

bool	are_patterns_found(char *str, char *file,
			int first_asterisk_index, int last_asterisk_index)
{
	int		available_file_start;
	int		available_file_end;
	t_lstr	available_file;
	t_lstr	matching_leftover;

	available_file_start = -1;
	available_file_end = -1;
	if (!is_first_pattern_found(str, file,
			first_asterisk_index, &available_file_start)
		|| !is_last_pattern_found(str, file,
			last_asterisk_index, &available_file_end))
		return (false);
	if (first_asterisk_index == last_asterisk_index)
		return (true);
	available_file = (t_lstr){file + available_file_start,
		available_file_end - available_file_start + 1};
	matching_leftover = (t_lstr){str + first_asterisk_index,
		last_asterisk_index - first_asterisk_index + 1};
	if (!are_middle_patterns_found(&available_file, matching_leftover))
		return (false);
	return (true);
}
