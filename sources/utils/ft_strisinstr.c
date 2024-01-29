/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisinstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 23:40:40 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/27 23:48:51 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "parsing.h"

bool	ft_strisinstr(char *str_to_find, char *str_to_search)
{
	int	i;
	int	str_to_find_len;
	int	str_to_search_len;
	int	max_i;

	i = 0;
	str_to_find_len = ft_strlen(str_to_find);
	str_to_search_len = ft_strlen(str_to_search);
	max_i = str_to_search_len - str_to_find_len;
	if (max_i < 0)
		return (false);
	while (i <= max_i)
	{
		if (ft_lstrcmp((t_lstr){str_to_find, str_to_find_len},
			(t_lstr){str_to_search + i, str_to_find_len}) == 0)
			return (true);
		i++;
	}
	return (false);
}
