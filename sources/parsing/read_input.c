/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 14:37:58 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/28 11:53:04 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	read_input(t_session *session, t_cstr *input)
{
	bool	did_get_line;

	did_get_line = false;
	while (!did_get_line)
	{
		input->str = readline("minishell$ ");
		if (!input->str)
			ft_exit((char *[]){"exit", NULL}, session);
		if (input->str[0])
			did_get_line = true;
		else
			free(input->str);
	}
	input->cursor = 0;
	return (1);
}
