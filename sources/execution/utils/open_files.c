/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 20:09:23 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/28 10:59:33 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	open_input_file(int *rd_end, t_redir *input_redir)
{
	if (input_redir->type == INPUT_REDIR)
		*rd_end = open(input_redir->file, O_RDONLY, 00666);
	if (input_redir->type == HEREDOC_REDIR)
		*rd_end = -2;
}

void	open_output_file(int *wr_end, t_redir *output_redir)
{
	if (output_redir->type == OUTPUT_REDIR)
		*wr_end = open(output_redir->file,
				O_WRONLY | O_CREAT | O_TRUNC, 00666);
	if (output_redir->type == OUTPUT_APPEND_REDIR)
		*wr_end = open(output_redir->file,
				O_WRONLY | O_CREAT | O_APPEND, 00666);
}
