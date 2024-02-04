/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes_stra.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 16:29:21 by ekhaled           #+#    #+#             */
/*   Updated: 2024/02/03 17:13:42 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_new_unquoted_len(t_exp_str exp_str)
{
	static t_quotes	quotes = (t_quotes){false, 0};
	int				i;
	int				len;

	i = 0;
	len = 0;
	while (exp_str.str[i])
	{
		if (!quotes.is_in && ft_charisinset(exp_str.str[i], "'\"")
			&& !is_index_in_range(i, &exp_str.range_array, NULL))
			quotes = (t_quotes){true, exp_str.str[i]};
		else if (exp_str.str[i] == quotes.type
			&& !is_index_in_range(i, &exp_str.range_array, NULL))
			quotes = (t_quotes){false, 0};
		else
			len++;
		i++;
	}
	return (len);
}

void	fill_unquoted_new_str(char *unquoted_str, t_exp_str exp_str)
{
	static t_quotes	quotes = (t_quotes){false, 0};
	int				i;
	int				j;

	i = 0;
	j = 0;
	while (exp_str.str[i])
	{
		if (!quotes.is_in && ft_charisinset(exp_str.str[i], "'\"")
			&& !is_index_in_range(i, &exp_str.range_array, NULL))
			quotes = (t_quotes){true, exp_str.str[i]};
		else if (exp_str.str[i] == quotes.type
			&& !is_index_in_range(i, &exp_str.range_array, NULL))
			quotes = (t_quotes){false, 0};
		else
		{
			unquoted_str[j] = exp_str.str[i];
			j++;
		}
		i++;
	}
	unquoted_str[j] = 0;
}

bool	fill_unquoted_stra(char **unquoted_str_array,
			t_exp_str_array exp_str_array)
{
	int		i;
	int		len;

	i = 0;
	while (i < exp_str_array.len)
	{
		len = get_new_unquoted_len(exp_str_array.array[i]);
		unquoted_str_array[i] = malloc((len + 1) * sizeof(char));
		if (!unquoted_str_array[i])
		{
			ft_free_words(unquoted_str_array, i);
			return (0);
		}
		fill_unquoted_new_str(unquoted_str_array[i], exp_str_array.array[i]);
		i++;
	}
	unquoted_str_array[i] = NULL;
	return (1);
}

char	**remove_quotes_stra(t_exp_str_array exp_str_array)
{
	char	**unquoted_str_array;

	unquoted_str_array = malloc((exp_str_array.len + 1) * sizeof(char *));
	if (!unquoted_str_array)
		return (NULL);
	if (!fill_unquoted_stra(unquoted_str_array, exp_str_array))
		return (NULL);
	unquoted_str_array[exp_str_array.len] = NULL;
	return (unquoted_str_array);
}
