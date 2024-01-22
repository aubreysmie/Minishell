/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_asterisks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 02:40:32 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/20 04:23:12 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	has_interpretable_asterisk(char *str)
{
	t_quotes	quotes;
	int			i;

	quotes = (t_quotes){false, 0};
	i = 0;
	while (str[i])
	{
		update_quoting(&quotes, str, i);
		if (!quotes.is_in && str[i] == '*')
			return (true);
		i++;
	}
	return (false);
}

int	find_first_asterisk(char *str)
{
	t_quotes	quotes;
	int			i;

	quotes = (t_quotes){false, 0};
	i = 0;
	while (str[i])
	{
		update_quoting(&quotes, str, i);
		if (!quotes.is_in && str[i] == '*')
			return (i);
		i++;
	}
	return (-1);
}

int	find_last_asterisk(char *str)
{
	t_quotes	quotes;
	int			i;

	quotes = (t_quotes){false, 0};
	i = ft_max(0, ft_strlen(str) - 1);
	while (i)
	{
		update_quoting(&quotes, str, i);
		if (!quotes.is_in && str[i] == '*')
			return (i);
		i--;
	}
	if (!quotes.is_in && str[i] == '*')
		return (i);
	return (-1);
}
