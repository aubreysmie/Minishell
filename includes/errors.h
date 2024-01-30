/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 22:19:27 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/30 07:44:17 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# include "parsing.h"

void	disp_access_error(char *file, char *arg, char *error);
void	disp_token_error(enum e_token_type token_type);
void	disp_eof_warning(char *delimiter);

#endif
