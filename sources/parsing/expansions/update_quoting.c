/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_quoting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 23:45:10 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/16 23:45:32 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "utils.h"

void	update_quoting(t_quotes *quotes, char *str, int i)
{
	if (!quotes->is_in && ft_charisinset(str[i], "'\""))
		*quotes = (t_quotes){true, str[i]};
	else if (str[i] == quotes->type)
		*quotes = (t_quotes){false, 0};
}
