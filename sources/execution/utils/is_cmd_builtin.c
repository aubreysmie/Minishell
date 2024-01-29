/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_cmd_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 08:00:40 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/28 08:00:51 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_cmd_builtin(char *cmd_name)
{
	return (ft_strisinstra(cmd_name, (char *[])
			{"echo", "cd", "pwd", "export", "unset", "env", "exit", NULL}));
}
