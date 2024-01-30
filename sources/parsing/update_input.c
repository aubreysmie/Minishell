/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 06:07:26 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/30 00:53:46 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	update_input(t_cstr *input)
{
	char	*og_input_str;
	char	*new_input_str;

	og_input_str = input->str;
	new_input_str = readline("> ");
	if (!new_input_str)
		return (1);
	input->str
		= ft_strajoin((char *[]){og_input_str, "\n", new_input_str, NULL});
	free(og_input_str);
	free(new_input_str);
	if (!input->str)
		return (0);
	return (1);
}
