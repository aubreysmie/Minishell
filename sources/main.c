/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 21:01:30 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/07 19:34:44 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_session	session;

	(void)argv;
	if (argc != 1)
	{
		write(2, "Error : Minishell takes no argument.\n", 37);
		return (EXIT_FAILURE);
	}
	if (!init_session(&session, envp))
	{
		destroy_session(&session);
		return (EXIT_FAILURE);
	}
	destroy_session(&session);
	return (session.last_cmd_status);
}
