/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 00:29:37 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/21 00:43:41 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include "utils.h"

static unsigned int	ft_count_words(const char *s, char set[])
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = 0;
	while (s[i])
	{
		if (!ft_charisinset(s[i], set)
			&& (ft_charisinset(s[i + 1], set) || s[i + 1] == 0))
			len++;
		i++;
	}
	return (len);
}

static void	ft_free_words(char **res, unsigned int end)
{
	unsigned int	i;

	i = 0;
	while (i < end)
	{
		free(res[i]);
		i++;
	}
	free(res);
}

static void	ft_fill_word(char *word, const char *s,
				unsigned int start, unsigned int end)
{
	unsigned int	i;

	i = 0;
	while (start + i != end)
	{
		word[i] = s[start + i];
		i++;
	}
	word[i] = '\0';
}

static bool	ft_create_words(const char *s, char set[],
				char **res, unsigned int len)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	i = 0;
	k = 0;
	while (k < len)
	{
		while (ft_charisinset(s[i], set))
			i++;
		j = i;
		while (s[j] != 0 && !ft_charisinset(s[j], set))
			j++;
		res[k] = malloc((j - i + 1) * sizeof(char));
		if (!res[k])
		{
			ft_free_words(res, k);
			return (0);
		}
		ft_fill_word(res[k], s, i, j);
		k++;
		i = j;
	}
	return (1);
}

char	**ft_splitset(char const *s, char set[])
{
	char			**res;
	unsigned int	array_len;

	if (!s)
		return (NULL);
	array_len = ft_count_words(s, set);
	res = malloc((array_len + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	res[array_len] = NULL;
	if (!ft_create_words(s, set, res, array_len))
		return (NULL);
	return (res);
}
