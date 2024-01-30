/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp_eof_warning.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 01:06:45 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/30 01:13:36 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "utils.h"

void	disp_eof_warning(char *delimiter)
{
	write(2, "minishell", 9);
	write(2, ": ", 2);
	write(2, "warning", 7);
	write(2, ": ", 2);
	write(2, "here-document delimited by end-of-file (wanted `", 49);
	write(2, delimiter, ft_strlen(delimiter));
	write(2, "')", 2);
	write(2, "\n", 1);
}
