/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 14:37:58 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/17 18:26:42 by ekhaled          ###   ########.fr       */
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
		if (input->str[0])
		{
			add_history(*input_str);
			if (!ft_straadd(&session->history, *input_str))
				return (0);
			did_get_line = true;
		}
		else
			free(input->str);
	}
	input->cursor = 0;
	return (1);
}
