/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 04:31:04 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/22 08:39:41 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "parsing.h"

char	*find_var(char *arg, char **env)
{
	t_lstr	lvar;
	t_lstr	larg;
	int		i;

	i = 0;
	larg = (t_lstr){arg, ft_strlen(arg)};
	while (env[i])
	{
		lvar = (t_lstr){env[i], ft_strchri(env[i], '=')};
		if (ft_lstrcmp(lvar, larg) == 0)
			return (env[i]);
		i++;
	}
	return (NULL);
}

int	ft_unset(char **argv, char ***env_p)
{
	int		i;
	char	*var;

	i = 1;
	while (argv[i])
	{
		var = find_var(argv[i], *env_p);
		if (var)
		{
			if (!ft_strarm(env_p, var))
				return (-1);
			free(var);
		}
		i++;
	}
	return (0);
}
