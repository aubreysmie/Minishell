/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_std_io.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 02:26:03 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/28 12:28:12 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	save_std_io(t_io_fd *std_io_save)
{
	std_io_save->rd_end = dup(STDIN_FILENO);
	if (std_io_save->rd_end == -1)
		return (0);
	std_io_save->wr_end = dup(STDOUT_FILENO);
	if (std_io_save->wr_end == -1)
		return (0);
	return (1);
}

bool	restore_std_io(t_io_fd *std_io_save)
{
	if (dup2(std_io_save->rd_end, STDIN_FILENO) == -1)
		return (0);
	close(std_io_save->rd_end);
	if (dup2(std_io_save->wr_end, STDOUT_FILENO) == -1)
		return (0);
	close(std_io_save->wr_end);
	return (1);
}
