/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 00:32:49 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/22 08:38:19 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "utils.h"

int	ft_env(char **argv, char ***env_p)
{
	int	i;

	if (!(ft_stralen(argv) == 1))
		return (0);
	i = 0;
	while ((*env_p)[i])
	{
		printf("%s\n", (*env_p)[i]);
		i++;
	}
	return (0);
}
