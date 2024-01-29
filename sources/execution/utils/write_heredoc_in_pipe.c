/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_heredoc_in_pipe.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 08:14:31 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/28 11:13:04 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	write_heredoc_in_pipe(int pipefd[2], char *heredoc)
{
	close(pipefd[0]);
	if (write(pipefd[1], heredoc, ft_strlen(heredoc)) == -1)
	{
		close(pipefd[1]);
		return (0);
	}
	close(pipefd[1]);
	return (1);
}
