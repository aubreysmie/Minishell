/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_and_exit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 02:28:33 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/29 10:19:22 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	destroy_and_exit(int exit_status, t_session *session)
{
	ft_queuefree(session->current_cmd_info.token_queue);
	free_ast(session->current_cmd_info.ast);
	destroy_session(session);
	exit(exit_status);
}
