/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 01:19:26 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/31 08:59:30 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdio.h>

#include "minishell.h"

bool	is_n_option(char *str)
{
	int	i;

	if (!str)
		return (false);
	i = 0;
	if (str[i] != '-')
		return (false);
	i++;
	if (str[i] != 'n')
		return (false);
	i++;
	while (str[i])
	{
		if (str[i] != 'n')
			return (false);
		i++;
	}
	return (true);
}

int	ft_echo(char **argv)
{
	int		i;
	bool	should_output_newline;

	i = 1;
	should_output_newline = !is_n_option(argv[i]);
	while (is_n_option(argv[i]))
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
