/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 22:01:51 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/22 08:34:14 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

int	export(char **argv, char ***env_p);
int	env(char **argv, char ***env_p);
int	unset(char **argv, char ***env_p);
int	pwd(char **argv, char ***env_p);
int	echo(char **argv);

#endif