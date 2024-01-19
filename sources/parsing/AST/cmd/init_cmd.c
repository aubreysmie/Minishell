/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 05:31:06 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/19 05:31:42 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_cmd(t_cmd *cmd)
{
	cmd->cmd_name = NULL;
	cmd->cmd_args = NULL;
	cmd->input_redir = (t_redir){-1, {NULL}};
	cmd->output_redir = (t_redir){-1, {NULL}};
}
