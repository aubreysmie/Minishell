/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_wildcards_exp.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 11:51:19 by ekhaled           #+#    #+#             */
/*   Updated: 2024/02/04 15:04:39 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	fill_exp_str_array(t_exp_str *exp_str_array, char **str_array)
{
	int		i;

	i = 0;
	while (str_array[i])
	{
		exp_str_array[i].is_expanded = true;
		exp_str_array[i].range_array = (t_range_array){NULL, 0};
		if (!ft_rangeaadd(&exp_str_array[i].range_array,
				(t_range){false, 0, ft_strlen(str_array[i])}))
			return (ft_strafree(str_array), 0);
		exp_str_array[i].str = str_array[i];
		i++;
	}
	free(str_array);
	return (1);
}

bool	get_exp_stra_from_exp_str(t_exp_str exp_str,
			t_exp_str_array *wildcards_exp_str_array)
{
	char	**str_array;

	str_array = match_patterns(exp_str.str);
	if (!str_array)
		return (0);
	if (ft_stralen(str_array) == 1 && str_array[0] == exp_str.str)
	{
		if (!ft_expstraadd(wildcards_exp_str_array, ft_expstrdup(exp_str)))
			return (ft_strafree(str_array), 0);
		free(str_array);
		return (1);
	}
	wildcards_exp_str_array->len = ft_stralen(str_array);
	wildcards_exp_str_array->array
		= malloc(wildcards_exp_str_array->len * sizeof(t_exp_str));
	if (!wildcards_exp_str_array->array)
		return (ft_strafree(str_array), 0);
	if (!fill_exp_str_array(wildcards_exp_str_array->array, str_array))
		return (free(wildcards_exp_str_array->array), 0);
	return (1);
}

bool	update_new_exp_stra(t_exp_str_array *new_exp_str_array,
			t_exp_str exp_str)
{
	t_exp_str_array	wildcards_exp_str_array;

	wildcards_exp_str_array = (t_exp_str_array){NULL, 0};
	get_exp_stra_from_exp_str(exp_str,
		&wildcards_exp_str_array);
	if (wildcards_exp_str_array.len == 1
		&& wildcards_exp_str_array.array[0].str
		== exp_str.str)
	{
		if (!ft_expstraadd(new_exp_str_array,
				ft_expstrdup(exp_str)))
			return (0);
		ft_expstrafree(wildcards_exp_str_array);
	}
	else
	{
		if (!ft_expstrajoin(new_exp_str_array,
				&wildcards_exp_str_array))
			return (0);
	}
	return (1);
}

bool	add_wildcards_exp(t_exp_str_array *exp_str_array)
{
	t_exp_str_array	new_exp_str_array;
	int				i;

	i = 0;
	new_exp_str_array = (t_exp_str_array){NULL, 0};
	while (i < exp_str_array->len)
	{
		if (!update_new_exp_stra(&new_exp_str_array,
				exp_str_array->array[i]))
		{
			free(new_exp_str_array.array);
			return (0);
		}
		i++;
	}
	ft_expstrafree(*exp_str_array);
	*exp_str_array = new_exp_str_array;
	return (1);
}
