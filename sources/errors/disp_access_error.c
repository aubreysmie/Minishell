/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp_access_error.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 22:14:51 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/28 09:59:17 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <unistd.h>

#include "errors.h"
#include "utils.h"

void	disp_access_error(bool should_print_minishell,
			char *file, char *arg, char *error)
{
	if (should_print_minishell)
		write(2, "minishell", 9);
	write(2, ": ", 2);
	write(2, file, ft_strlen(file));
	write(2, ": ", 2);
	if (arg)
	{
		write(2, arg, ft_strlen(arg));
		write(2, ": ", 2);
	}
	write(2, error, ft_strlen(error));
	write(2, "\n", 1);
}
