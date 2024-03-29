/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_session.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:37:28 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/31 11:38:14 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "session.h"

void	destroy_session(t_session *session)
{
	rl_clear_history();
	ft_strafree(session->env);
	ft_strafree(session->history);
}
