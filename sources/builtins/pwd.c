/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 21:12:56 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/06 21:24:59 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	pwd(char **argv, char ***env_p)
{
	char	*path;

	(void) argv;
	(void) env_p;
	path = getcwd(NULL, 0);
	if (!path)
		return (-1);
	printf("%s\n", path);
	free(path);
	return (0);
}
