/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 22:01:51 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/06 21:19:49 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

int	export(char **argv, char ***env_p);
int	env(char **argv, char ***env_p);
int	unset(char **argv, char ***env_p);
int	pwd(char **argv, char ***env_p);

#endif