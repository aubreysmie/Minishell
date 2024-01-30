/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_parameters.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 20:04:38 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/16 23:45:01 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "session.h"
#include "parsing.h"
#include "utils.h"

bool	append_between_vars_str(char **expanded_str_p, char *str,
			int var_end, int i)
{
	char	*temp;
	char	*between_vars;

	between_vars = ft_substrrange(str, var_end + 1, i - 1);
	if (!between_vars)
		return (0);
	temp = *expanded_str_p;
	*expanded_str_p = ft_strjoin(*expanded_str_p, between_vars);
	free(temp);
	free(between_vars);
	return (*expanded_str_p);
}

char	*find_variable_value(t_lstr name, t_session *session)
{
	int		equal_index;
	int		len;
	int		i;

	i = 0;
	if (name.len == 0)
		return (ft_strdup("$"));
	if (name.str[0] == '?')
		return (ft_uitoa(session->last_cmd_status));
	while (session->env[i])
	{
		equal_index = ft_strchri(session->env[i], '=');
		if (ft_lstrcmp(name, (t_lstr){session->env[i], equal_index}) == 0)
		{
			len = ft_strlen(session->env[i]);
			return (ft_substrrange(
					session->env[i], equal_index + 1, len - 1));
		}
		i++;
	}
	return (ft_strdup(""));
}

bool	append_var_str(char **expanded_str_p,
			char *str, int *i_p, t_session *session)
{
	t_lstr	name;
	t_lstr	name_candidate;
	char	*var_val;
	char	*temp;
	int		j;

	j = 1;
	name = (t_lstr){NULL, 0};
	name_candidate = (t_lstr){str + (*i_p) + 1, j};
	while (is_name(name_candidate))
	{
		name = name_candidate;
		j++;
		name_candidate = (t_lstr){str + (*i_p) + 1, j};
	}
	*i_p += name.len;
	temp = *expanded_str_p;
	var_val = find_variable_value(name, session);
	if (!var_val)
		return (0);
	*expanded_str_p = ft_strjoin(*expanded_str_p, var_val);
	free(temp);
	free(var_val);
	return (*expanded_str_p);
}

char	*expand_parameters(char *str, t_session *session)
{
	t_quotes		quotes;
	int				i;
	int				var_end;
	char			*expanded_str;

	quotes = (t_quotes){false, 0};
	i = 0;
	var_end = -1;
	expanded_str = NULL;
	while (str[i])
	{
		update_quoting(&quotes, str, i);
		if ((!quotes.is_in || quotes.type == '"' ) && str[i] == '$')
		{
			if (!append_between_vars_str(&expanded_str, str, var_end, i))
				return (free(expanded_str), NULL);
			if (!append_var_str(&expanded_str, str, &i, session))
				return (free(expanded_str), NULL);
			var_end = i;
		}
		i++;
	}
	if (!append_between_vars_str(&expanded_str, str, var_end, i))
		return (free(expanded_str), NULL);
	return (expanded_str);
}
