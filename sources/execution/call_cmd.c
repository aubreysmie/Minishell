/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 23:33:18 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/29 10:43:41 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**get_paths_from_var(char *path_var)
{
	char	**paths;

	paths = ft_split(path_var + 5, ':');
	if (!paths)
		return (NULL);
	if (ft_strisinstr("::", path_var + 5))
	{
		if (!ft_straadd(&paths, "."))
		{
			ft_strafree(paths);
			return (NULL);
		}
	}
	return (paths);
}

char	**get_paths_from_env(char **env)
{
	int		i;

	if (!env)
		return (NULL);
	i = 0;
	while (env[i])
	{
		if (ft_lstrcmp((t_lstr){"PATH=", 5}, (t_lstr){env[i], 5}) == 0)
			return (get_paths_from_var(env[i]));
		i++;
	}
	return (NULL);
}

bool	call_path_cmd(char *cmd_name, char **cmd_args, char **env, char **paths)
{
	int		i;
	char	*temp_cmd;

	i = 0;
	while (paths[i])
	{
		temp_cmd = ft_strajoin((char *[]){paths[i], "/", cmd_name, NULL});
		if (!temp_cmd)
			return (0);
		if (access(temp_cmd, X_OK) == 0)
			if (execve(temp_cmd, cmd_args, env) == -1)
				return (free(temp_cmd), 0);
		free(temp_cmd);
		i++;
	}
	return (1);
}

bool	call_cmd(char *cmd_name, char **cmd_args, char **env,
			int *last_cmd_status_p)
{
	char	**paths;

	if (ft_charisinset('/', cmd_name))
		if (execve(cmd_name, cmd_args, env) == -1)
			return (0);
	paths = get_paths_from_env(env);
	if (!paths)
		return (0);
	if (!call_path_cmd(cmd_name, cmd_args, env, paths))
	{
		free(paths);
		return (0);
	}
	ft_strafree(paths);
	disp_access_error(cmd_name, NULL, "command not found");
	*last_cmd_status_p = errno;
	return (1);
}
