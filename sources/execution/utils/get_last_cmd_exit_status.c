/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_last_cmd_exit_status.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 22:59:22 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/28 01:43:02 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_last_cmd_exit_status(int cpid)
{
	int	wstatus;
	int	terminated_child;
	int	last_cmd_exit_status;

	terminated_child = waitpid(cpid, &wstatus, 0);
	if (WIFEXITED(wstatus))
		last_cmd_exit_status = WEXITSTATUS(wstatus);
	terminated_child = wait(&wstatus);
	while (!(terminated_child == -1 && errno == ECHILD))
		terminated_child = wait(&wstatus);
	return (last_cmd_exit_status);
}
