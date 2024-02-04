/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expstrajoin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 11:26:31 by ekhaled           #+#    #+#             */
/*   Updated: 2024/02/03 12:09:09 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_expstrajoinfill(t_exp_str*new_exp_str_array,
			t_exp_str_array *exp_str_array1,
			t_exp_str_array *exp_str_array2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < exp_str_array1->len)
	{
		new_exp_str_array[i] = exp_str_array1->array[i];
		i++;
	}
	while (j < exp_str_array2->len)
	{
		new_exp_str_array[i + j] = exp_str_array2->array[j];
		j++;
	}
}

bool	ft_expstrajoin(t_exp_str_array *exp_str_array1,
			t_exp_str_array *exp_str_array2)
{
	t_exp_str	*new_exp_str_array;
	int			len;

	if (!exp_str_array1 || !exp_str_array2)
		return (0);
	if (exp_str_array1->len == 0)
	{
		*exp_str_array1 = *exp_str_array2;
		return (1);
	}
	if (exp_str_array2->len == 0)
	{
		*exp_str_array2 = *exp_str_array1;
		return (1);
	}
	len = exp_str_array1->len + exp_str_array1->len;
	new_exp_str_array = malloc(len * sizeof(t_exp_str));
	if (!new_exp_str_array)
		return (0);
	ft_expstrajoinfill(new_exp_str_array, exp_str_array1, exp_str_array2);
	free(exp_str_array1->array);
	free(exp_str_array2->array);
	exp_str_array1->array = new_exp_str_array;
	exp_str_array1->len = len;
	return (1);
}
