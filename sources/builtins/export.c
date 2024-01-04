/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 22:01:27 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/04 04:18:06 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdio.h>

#include "utils.h"
#include "parsing.h"
#include "errors.h"

static bool	is_proper_arg(char *arg)
{
	int		arg_len;
	int		equal_index;
	t_lstr	name_candidate;
	t_lstr	word_candidate;

	arg_len = ft_strlen(arg);
	equal_index = ft_strchri(arg, '=');
	if (equal_index == -1)
	{
		name_candidate = (t_lstr){arg, arg_len};
		return (is_name(name_candidate));
	}
	name_candidate = (t_lstr){arg, equal_index};
	word_candidate = (t_lstr){arg + equal_index + 1, arg_len - equal_index};
	return (is_name(name_candidate) && is_word(word_candidate));
}

int	export(char **argv, char ***env_p)
{
	int	exit_status;
	int	i;

	if (ft_stralen(argv) == 1)
		return (0);
	exit_status = 0;
	i = 1;
	while (argv[i])
	{
		if (is_proper_arg(argv[i]))
		{
			if (ft_strchri(argv[i], '=') != -1)
				if (!ft_straadd(env_p, ft_strdup(argv[i])))
					return (-1);
		}
		else
		{
			disp_error(SHOULD_PRINT_SHELL,
				"export", argv[i], "not a valid identifier");
			exit_status = 1;
		}
		i++;
	}
	return (exit_status);
}
