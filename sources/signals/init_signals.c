/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_signals.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:22:35 by ekhaled           #+#    #+#             */
/*   Updated: 2024/02/04 19:55:13 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_sigint(int sig)
{
	(void)sig;
	g_signum = 130;
	write(2, "\n", 1);
	if (waitpid(-1, NULL, WNOHANG) != -1)
		return ;
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void	init_signals_parent(void)
{
	struct sigaction	sa_int;
	struct sigaction	sa_quit;

	sa_int.sa_flags = SA_RESTART;
	sa_quit.sa_flags = SA_RESTART;
	sigemptyset(&sa_int.sa_mask);
	sigemptyset(&sa_quit.sa_mask);
	sa_int.sa_handler = &handle_sigint;
	sa_quit.sa_handler = SIG_IGN;
	sigaction(SIGINT, &sa_int, NULL);
	sigaction(SIGQUIT, &sa_quit, NULL);
}

void	init_signals_child(void)
{
	struct sigaction	sa_quit;

	sa_quit.sa_flags = SA_RESTART;
	sigemptyset(&sa_quit.sa_mask);
	sa_quit.sa_handler = SIG_DFL;
	sigaction(SIGQUIT, &sa_quit, NULL);
}
