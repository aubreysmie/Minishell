/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 21:01:30 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/30 09:56:35 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_signum = 0;

bool	run_exec_loop(t_session *session)
{
	while (session->cmd_info.token_queue)
	{
		if (!generate_ast(&session->cmd_info.input,
				&session->cmd_info.token_queue,
				&session->cmd_info.heredoc_queue,
				&session->cmd_info.ast))
			return (ft_queuefree(session->cmd_info.token_queue),
				ft_queuefree(session->cmd_info.token_queue),
				free_ast(session->cmd_info.ast), 0);
		skip_newlines(&session->cmd_info.token_queue);
		add_history(session->cmd_info.input.str);
		if (!ft_straadd(&session->history, session->cmd_info.input.str))
			return (ft_queuefree(session->cmd_info.token_queue),
				ft_queuefree(session->cmd_info.token_queue),
				free_ast(session->cmd_info.ast), 0);
		if (!session->cmd_info.ast)
		{
			session->last_cmd_status = 2;
			continue ;
		}
		execute_ast(session->cmd_info.ast, session);
		free_ast(session->cmd_info.ast);
	}
	return (1);
}

void	check_signals(int *last_cmd_status_p)
{
	if (g_signum != -1)
			*last_cmd_status_p = g_signum;
	g_signum = -1;
}

bool	run_repl(t_session *session)
{
	while (true)
	{
		session->cmd_info = (t_cmd_info){(t_cstr){NULL, 0}, NULL, NULL, NULL};
		if (!read_input(session, &session->cmd_info.input))
			return (0);
		check_signals(&session->last_cmd_status);
		if (!generate_tokens(&session->cmd_info.input,
				&session->cmd_info.token_queue,
				&session->cmd_info.heredoc_queue))
			return (0);
		skip_newlines(&session->cmd_info.token_queue);
		if (!run_exec_loop(session))
			return (0);
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
