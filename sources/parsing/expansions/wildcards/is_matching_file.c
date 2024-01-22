/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_matching_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 00:24:49 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/20 23:31:08 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	are_unquoted_strs_eq(char *str, char *file)
{
	t_quotes	quotes;
	int			i;
	int			j;

	quotes = (t_quotes){false, 0};
	i = 0;
	j = 0;
	while (str[i])
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
	if (file[j])
		return (false);
	return (true);
}

bool	is_matching_file(char *str, char *file)
{
	int	first_asterisk_index;
	int	last_asterisk_index;

	if (file[0] == '.' && str[0] != '.')
		return (false);
	if (!has_interpretable_asterisk(str))
		return (are_unquoted_strs_eq(str, file));
	first_asterisk_index = find_first_asterisk(str);
	last_asterisk_index = find_last_asterisk(str);
	if (!are_patterns_found(str, file,
			first_asterisk_index, last_asterisk_index))
		return (false);
	return (true);
}
