/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 22:01:51 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/29 12:17:07 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "session.h"

void	ft_exit(char **argv, t_session *session);
int		ft_export(char **argv, char ***env_p);
int		ft_env(char **argv, char ***env_p);
int		ft_unset(char **argv, char ***env_p);
int		ft_cd(char **argv, char ***env_p);
int		ft_echo(char **argv);
int		ft_pwd(void);

#endif
