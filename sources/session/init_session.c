/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_session.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:37:30 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/07 19:41:11 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "session.h"
#include "builtins.h"

static bool	restore_hist(void)
{
	int		fd;
	char	*line;

	fd = open(".minishell_history", O_RDONLY);
	if (fd == -1)
		return (1);
	if (!get_next_line(&line, fd))
		return (0);
	while (line)
	{
		line[ft_strlen(line) - 1] = 0;
		add_history(line);
		free(line);
		if (!get_next_line(&line, fd))
			return (0);
	}
	free(line);
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
	if (export((char *[]){"export", pwd_var, NULL}, env_p))
	{
		free(pwd_var);
		return (0);
	}
	free(pwd_var);
	if (export((char *[]){"export", "SHLVL=1", NULL}, env_p))
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
	session->env = NULL;
	session->history = NULL;
	session->last_cmd_status = 0;
	session->should_exit = false;
	if (!(init_env(&session->env, envp)))
		return (0);
	if (!restore_hist())
		return (0);
	return (1);
}
