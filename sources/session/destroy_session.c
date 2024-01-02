/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_session.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:37:28 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/02 07:07:19 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "session.h"

void	add_history_to_histfile(char **history)
{
	int				fd;
	unsigned int	i;

	if (!history)
		return ;
	fd = open(".minishell_history", O_WRONLY | O_APPEND | O_CREAT, 00600);
	if (fd == -1)
		return ;
	i = 0;
	while (history[i])
	{
		write(fd, history[i], ft_strlen(history[i]));
		write(fd, "\n", 1);
		i++;
	}
	close(fd);
}

void	destroy_session(t_session *session)
{
	add_history_to_histfile(session->history);
	rl_clear_history();
	ft_strafree(session->env);
	ft_strafree(session->history);
}
