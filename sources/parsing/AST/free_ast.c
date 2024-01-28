/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:19:32 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/23 22:17:35 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_ast(t_ast ast)
{
	if (!ast)
		return ;
	if (ast->left_child)
		free_ast(ast->left_child);
	if (ast->right_child)
		free_ast(ast->right_child);
	if (ast->type == CMD_NODE)
		free_cmd(&ast->cmd);
	free(ast);
}
