/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 22:19:27 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/03 22:25:29 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# define SHOULD_PRINT_SHELL 1

void	disp_error(bool should_print_minishell,
			char *cmd, char *arg, char *error);

#endif