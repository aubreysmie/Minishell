/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_history_to_histfile.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:38:33 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/31 11:38:48 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
