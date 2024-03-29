/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_session.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:37:30 by ekhaled           #+#    #+#             */
/*   Updated: 2024/02/04 19:54:15 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	restore_hist(void)
{
	int		fd;
	char	*line;

	fd = open(".minishell_history", O_RDONLY);
	if (fd == -1)
		return (1);
	if (!get_next_line(&line, fd))
		return (close(fd), 0);
	while (line)
	{
		line[ft_strlen(line) - 1] = 0;
		add_history(line);
		free(line);
		if (!get_next_line(&line, fd))
			return (close(fd), 0);
	}
	free(line);
	close(fd);
	return (1);
}

static bool	create_default_env(char ***env_p)
{
	char	*path;
	char	*pwd_var;

	path = getcwd(NULL, 0);
	if (!path)
		return (0);
	pwd_var = ft_strjoin("PWD=", path);
	free(path);
	if (!pwd_var)
		return (0);
	if (ft_export((char *[]){"export", pwd_var, NULL}, env_p))
	{
		free(pwd_var);
		return (0);
	}
	free(pwd_var);
	if (ft_export((char *[]){"export", "SHLVL=1", NULL}, env_p))
		return (0);
	return (1);
}

static bool	init_env(char ***session_env_p, char **envp)
{
	if (!envp[0])
	{
		if (!create_default_env(session_env_p))
			return (0);
	}
	else
	{
		*session_env_p = ft_stradup(envp);
		if (!(*session_env_p))
			return (0);
	}
	return (1);
}

bool	init_session(t_session *session, char **envp)
{
	init_signals_parent();
	session->env = NULL;
	session->history = NULL;
	session->last_cmd_status = 0;
	if (!(init_env(&session->env, envp)))
		return (0);
	if (!restore_hist())
		return (0);
	return (1);
}
