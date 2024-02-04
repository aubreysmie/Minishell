/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stra_to_exp_stra.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 00:54:26 by ekhaled           #+#    #+#             */
/*   Updated: 2024/02/03 16:51:09 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_exp_str(t_exp_str *exp_str, char *str)
{
	exp_str->is_expanded = false;
	exp_str->range_array = (t_range_array){NULL, 0};
	exp_str->str = str;
}

bool	str_to_exp_str(char *str, t_range_array *range_array,
			int *j_p, t_exp_str *exp_str)
{
	int			i;
	t_range		range;

	i = 0;
	init_exp_str(exp_str, str);
	while (str[i])
	{
		if (is_index_in_range(*j_p + i, range_array, &range.is_quoted))
		{
			exp_str->is_expanded = true;
			range = (t_range){false, i, 0};
			while (str[i] && is_index_in_range(*j_p + i, range_array, NULL))
				i++;
			range.end = i;
			if (!ft_rangeaadd(&exp_str->range_array, range))
				return (free(exp_str->range_array.array), 0);
			if (!str[i])
				break ;
		}
		i++;
	}
	*j_p += i;
	return (1);
}

bool	stra_to_exp_stra(char **str_array, t_range_array *range_array,
			t_exp_str_array *exp_str_array)
{
	int				i;
	int				j;
	t_exp_str		exp_str;

	i = 0;
	j = 0;
	while (str_array[i])
	{
		if (!str_to_exp_str(str_array[i], range_array, &j, &exp_str))
		{
			free(exp_str_array->array);
			return (NULL);
		}
		if (!ft_expstraadd(exp_str_array, exp_str))
		{
			free(exp_str_array->array);
			return (NULL);
		}
		i++;
	}
	return (1);
}
