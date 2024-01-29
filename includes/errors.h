/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 22:19:27 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/28 09:59:59 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# include "parsing.h"

# define SHOULD_PRINT_SHELL 1

void	disp_access_error(bool should_print_minishell,
			char *file, char *arg, char *error);
void	disp_token_error(enum e_token_type token_type);

#endif