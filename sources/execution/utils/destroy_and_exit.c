/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_and_exit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 02:28:33 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/31 22:22:52 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	destroy_and_exit(int exit_status, t_session *session)
{
	free(session->cmd_info.input.str);
	ft_queuefree(session->cmd_info.token_queue);
	free_ast(session->cmd_info.ast);
	destroy_session(session);
	exit(exit_status);
}
