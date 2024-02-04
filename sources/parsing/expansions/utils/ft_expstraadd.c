/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expstraadd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 02:46:14 by ekhaled           #+#    #+#             */
/*   Updated: 2024/02/03 12:44:15 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	ft_expstraaddnull(t_exp_str_array *exp_str_array,
			t_exp_str new_exp_str)
{
	t_exp_str	*new_exp_str_array;

	new_exp_str_array = malloc(1 * sizeof(t_exp_str));
	if (!new_exp_str_array)
		return (0);
	new_exp_str_array[0] = new_exp_str;
	exp_str_array->array = new_exp_str_array;
	exp_str_array->len = 1;
	return (1);
}

bool	ft_expstraadd(t_exp_str_array *exp_str_array, t_exp_str new_exp_str)
{
	t_exp_str	*new_exp_str_array;
	int			i;

	i = 0;
	if (!exp_str_array)
		return (0);
	if (exp_str_array->len == 0)
		return (ft_expstraaddnull(exp_str_array, new_exp_str));
	new_exp_str_array = malloc((exp_str_array->len + 1) * sizeof(t_exp_str));
	if (!new_exp_str_array)
		return (0);
	while (i < exp_str_array->len)
	{
		new_exp_str_array[i]
			= exp_str_array->array[i];
		i++;
	}
	new_exp_str_array[i] = new_exp_str;
	(exp_str_array->len)++;
	free(exp_str_array->array);
	exp_str_array->array = new_exp_str_array;
	return (1);
}
