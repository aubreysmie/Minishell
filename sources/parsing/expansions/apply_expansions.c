/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_expansions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 08:25:56 by ekhaled           #+#    #+#             */
/*   Updated: 2024/02/04 15:38:56 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	apply_variable_expansion(char *str, t_session *session,
			t_exp_str_array *exp_str_array)
{
	t_exp_str		exp_str;
	char			**expanded_str_array;

	exp_str = (t_exp_str){false, (t_range_array){NULL, 0}, NULL};
	if (!expand_parameters_and_save_range(str, session, &exp_str))
		return (0);
	if (exp_str.range_array.len != 0)
		exp_str.is_expanded = true;
	expanded_str_array = ft_splitset_unquoted_expansions(
			exp_str.str, &exp_str.range_array, " \n\t");
	free(exp_str.str);
	if (!expanded_str_array)
		return (free(exp_str.range_array.array), 0);
	if (!stra_to_exp_stra(
			expanded_str_array, &exp_str.range_array, exp_str_array))
	{
		free(exp_str.range_array.array);
		free(expanded_str_array);
		return (0);
	}
	free(exp_str.range_array.array);
	free(expanded_str_array);
	return (1);
}

char	**apply_expansions(char *str, t_session *session)
{
	char			**expanded_str_array;
	t_exp_str_array	exp_str_array;

	exp_str_array = (t_exp_str_array){NULL, 0};
	if (!apply_variable_expansion(str, session, &exp_str_array))
		return (NULL);
	if (!add_wildcards_exp(&exp_str_array))
		return (NULL);
	expanded_str_array = remove_quotes_stra(exp_str_array);
	ft_expstrafree(exp_str_array);
	if (!expanded_str_array)
		return (NULL);
	return (expanded_str_array);
}
