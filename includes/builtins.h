/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 22:01:51 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/22 08:42:33 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

#include "session.h"

int		ft_export(char **argv, char ***env_p);
int		ft_env(char **argv, char ***env_p);
int		ft_unset(char **argv, char ***env_p);
int		ft_pwd(void);
int		ft_echo(char **argv);
void	ft_exit(char **argv, t_session *session);

#endif