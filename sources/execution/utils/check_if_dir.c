/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_dir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:43:52 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/31 11:03:41 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	check_if_dir(char *name, bool *is_dir_p)
{
	struct stat	statbuf;

	if (stat(name, &statbuf) == -1)
		return (0);
	*is_dir_p = S_ISDIR(statbuf.st_mode);
	return (1);
}
