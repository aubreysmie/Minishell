/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_parameters_and_save_range.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:51:41 by ekhaled           #+#    #+#             */
/*   Updated: 2024/02/04 15:40:08 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minishell.h"

bool	update_end_of_exp_str(char *str,
			t_exp_str *exp_str, int i, int *var_end_p)
{
	if (!append_between_vars_str(&exp_str->str, str, *var_end_p, i))
		return (0);
	*var_end_p = -1;
	return (1);
}

bool	update_exp_str(char *str, t_session *session,
			t_exp_str *exp_str, int *i_p)
{
	static t_quotes		quotes = (t_quotes){false, 0};
	t_range				expanded_var_range;
	static int			var_end = -1;

	expanded_var_range = (t_range){false, 0, 0};
	if (!str[*i_p])
		return (update_end_of_exp_str(str, exp_str, *i_p, &var_end));
	update_quoting(&quotes, str, *i_p);
	if ((!quotes.is_in || quotes.type == '"' ) && str[*i_p] == '$')
	{
		expanded_var_range.is_quoted = quotes.is_in;
		if (!append_between_vars_str(&exp_str->str, str, var_end, *i_p))
			return (0);
		expanded_var_range.start = ft_strlen(exp_str->str);
		if (!append_var_str(&exp_str->str, str, i_p, session))
			return (0);
		expanded_var_range.end = ft_strlen(exp_str->str);
		if (!ft_rangeaadd(&exp_str->range_array, expanded_var_range))
			return (0);
		var_end = *i_p;
	}
	return (1);
}

bool	expand_parameters_and_save_range(char *str,
				t_session *session, t_exp_str *exp_str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!update_exp_str(str, session, exp_str, &i))
		{
			free(exp_str->str);
			return (0);
		}
		i++;
	}
	if (!update_exp_str(str, session, exp_str, &i))
	{
		free(exp_str->str);
		return (0);
	}
	return (1);
}
