/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 21:01:30 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/14 21:29:37 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	run_repl(t_session *session)
{
	t_cstr			input;
	t_token_queue	*token_queue;
	t_token_queue	*heredoc_queue;

	while (!session->should_exit)
	{
		if (!read_input(session, &input.str))
			return (0);
		if (!generate_tokens(&input, &token_queue, &heredoc_queue))
			return (0);
		ft_queuefree(token_queue);
		ft_queuefreeall(heredoc_queue);
	}
	return (1);
}

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
	if (!run_repl(&session))
	{
		destroy_session(&session);
		return (EXIT_FAILURE);
	}
	destroy_session(&session);
	return (session.last_cmd_status);
}
