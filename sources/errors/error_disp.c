/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_disp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 22:14:51 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/03 23:59:17 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <unistd.h>

#include "errors.h"
#include "utils.h"

void	disp_error(bool should_print_minishell,
			char *cmd, char *arg, char *error)
{
	if (should_print_minishell)
		write(2, "minishell", 9);
	write(2, ": ", 2);
	write(2, cmd, ft_strlen(cmd));
	write(2, ": ", 2);
	write(2, arg, ft_strlen(arg));
	write(2, ": ", 2);
	write(2, error, ft_strlen(error));
	write(2, "\n", 1);
}
