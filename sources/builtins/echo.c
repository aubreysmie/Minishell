/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 01:19:26 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/22 05:04:50 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdio.h>

#include "utils.h"

int	echo(char **argv, char ***env_p)
{
	int		i;
	bool	should_output_newline;

	i = 1;
	should_output_newline = !ft_strareeq(argv[i], "-n");
	while (ft_strareeq(argv[i], "-n"))
		i++;
	if (argv[i])
	{
		printf("%s", argv[i]);
		i++;
	}
	while (argv[i])
	{
		printf(" %s", argv[i]);
		i++;
	}
	if (should_output_newline)
		printf("\n");
	return (0);
}
