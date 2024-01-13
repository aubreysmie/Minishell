/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 00:34:34 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/13 03:40:02 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "parsing.h"
#include "utils.h"

unsigned int	get_new_len(char *str)
{
	t_quotes		quotes;
	unsigned int	i;
	unsigned int	len;

	quotes = (t_quotes){false, 0};
	i = 0;
	len = 0;
	while (str[i])
	{
		if (!quotes.is_in && ft_charisinset(str[i], "'\""))
			quotes = (t_quotes){true, str[i]};
		else if (str[i] == quotes.type)
			quotes = (t_quotes){false, 0};
		else
			len++;
		i++;
	}
	return (len);
}

void	fill_unquoted_str(char *unquoted_str, char *str)
{
	t_quotes		quotes;
	unsigned int	i;
	unsigned int	j;

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
			unquoted_str[j] = str[i];
			j++;
		}
		i++;
	}
	unquoted_str[j] = 0;
}

char	*remove_quotes(char *str)
{
	unsigned int	len;
	char			*unquoted_str;

	if (!str)
		return (NULL);
	len = get_new_len(str);
	unquoted_str = malloc((len + 1) * sizeof(char));
	if (!unquoted_str)
		return (NULL);
	fill_unquoted_str(unquoted_str, str);
	return (unquoted_str);
}
