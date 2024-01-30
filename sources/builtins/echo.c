/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 01:19:26 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/31 00:43:08 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdio.h>

#include "minishell.h"


int	ft_echo(char **argv)
{
	int		i;
	bool	should_output_newline;

	i = 1;
	should_output_newline = !ft_strareeq(argv[i], "-n");
	while (ft_strareeq(argv[i], "-n"))
		i++;
	if (argv[i])
	{
		write(1, argv[i], ft_strlen(argv[i]));
		i++;
	}
	while (argv[i])
	{
		write(1, " ", 1);
		write(1, argv[i], ft_strlen(argv[i]));
		i++;
	}
	if (should_output_newline)
		printf("\n");
	return (0);
}
