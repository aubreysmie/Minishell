/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitset_unquoted_expansions.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:54:22 by ekhaled           #+#    #+#             */
/*   Updated: 2024/02/02 10:48:44 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static unsigned int	ft_conditional_count_words(char const *s,
			t_range_array range_array, char set[])
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = 0;
	while (s[i])
	{
		if (!(ft_charisinset(s[i], set)
				&& is_accepted_del_index(i, range_array))
			&& ((ft_charisinset(s[i + 1], set)
					&& is_accepted_del_index(i + 1, range_array))
				|| s[i + 1] == 0))
			len++;
		i++;
	}
	return (len);
}

void	get_to_word(char const *s, t_range_array *range_array,
			char set[], t_range *word_range)
{
	while (ft_charisinset(s[word_range->end], set)
		&& is_accepted_del_index(word_range->end, *range_array))
			word_range->end++;
	update_range_offset(range_array, word_range->end - word_range->start);
	word_range->start = word_range->end;
	while (s[word_range->start] != 0
		&& !(ft_charisinset(s[word_range->start], set)
			&& is_accepted_del_index(word_range->start, *range_array)))
		word_range->start++;
}

char	**ft_conditional_create_words(char const *s,
			t_range_array *range_array, char set[], int array_len)
{
	t_range	word_range;
	int		k;
	char	**res;

	word_range = (t_range){false, 0, 0};
	k = 0;
	res = malloc((array_len + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	while (k < array_len)
	{
		get_to_word(s, range_array, set, &word_range);
		res[k] = malloc((word_range.start - word_range.end + 1) * sizeof(char));
		if (!res[k])
			return (ft_free_words(res, k), NULL);
		ft_fill_word(res[k], s, word_range.end, word_range.start);
		k++;
		word_range.end = word_range.start;
	}
	res[k] = NULL;
	return (res);
}

char	**ft_splitset_unquoted_expansions(char const *s,
			t_range_array *range_array, char set[])
{
	char			**res;
	unsigned int	array_len;

	if (!s)
		return (NULL);
	array_len = ft_conditional_count_words(s, *range_array, set);
	res = ft_conditional_create_words(s, range_array, set, array_len);
	if (!res)
		return (NULL);
	return (res);
}
