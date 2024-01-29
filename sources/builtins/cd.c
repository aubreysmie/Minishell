/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:27:41 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/29 12:13:21 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <errno.h>

#include "utils.h"
#include "errors.h"
#include "parsing.h"
#include "builtins.h"

char	**get_cdpaths(char **env)
{
	char	**cdpaths;
	char	*dup_temp;
	int		i;

	cdpaths = NULL;
	i = 0;
	while (env && env[i])
	{
		if (ft_lstrcmp((t_lstr){"CDPATH=", 7}, (t_lstr){env[i], 7}) == 0)
		{
			cdpaths = ft_split(env[i] + 7, ':');
			if (!cdpaths)
				return (NULL);
			break ;
		}
		i++;
	}
	dup_temp = ft_strdup(".");
	if (!dup_temp || !ft_straadd(&cdpaths, dup_temp))
	{
		free(dup_temp);
		ft_strafree(cdpaths);
		return (NULL);
	}
	return (cdpaths);
}

bool	change_path_dir(char *dir_path, char *current_path)
{
	if (chdir(dir_path) == 0)
	{
		if (!ft_strareeq(current_path, "."))
			ft_pwd();
		return (1);
	}
	return (0);
}

int	change_relative_dir(char *dir, char **env)
{
	char	**paths;
	int		i;
	char	*temp_path;

	paths = get_cdpaths(env);
	if (!paths)
		return (-1);
	i = 0;
	while (paths[i])
	{
		temp_path = ft_strajoin((char *[]){paths[i], "/", dir, NULL});
		if (!temp_path)
			return (ft_strafree(paths), -1);
		if (change_path_dir(temp_path, paths[i]))
		{
			ft_strafree(paths);
			free(temp_path);
			return (0);
		}
		free(temp_path);
		i++;
	}
	disp_access_error("cd", dir, strerror(errno));
	ft_strafree(paths);
	return (1);
}

int	change_abs_dir(char *dir)
{
	if (chdir(dir) == 0)
		return (0);
	disp_access_error("cd", dir, strerror(errno));
	return (1);
}

int	ft_cd(char **argv, char ***env_p)
{
	int	len;

	len = ft_stralen(argv);
	if (len == 1)
		return (0);
	if (len != 2)
	{
		disp_access_error(argv[0], NULL, "too many arguments");
		return (1);
	}
	if (argv[1][0] == '/')
		return (change_abs_dir(argv[1]));
	return (change_relative_dir(argv[1], *env_p));
}
