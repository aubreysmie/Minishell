/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match_patterns.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 05:11:46 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/30 23:08:37 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include "utils.h"
#include "parsing.h"

#include "debug_colors.h"

bool	get_files_names(char ***dir_files_p)
{
	DIR				*dirp;
	struct dirent	*dirent_struct;
	char			*dir_name;

	dirp = opendir("./");
	if (!dirp)
		return (0);
	*dir_files_p = NULL;
	dirent_struct = readdir(dirp);
	while (dirent_struct)
	{
		dir_name = ft_strdup(dirent_struct->d_name);
		if (!dir_name || !ft_straadd(dir_files_p, dir_name))
		{
			free(dir_name);
			ft_strafree(*dir_files_p);
			return (0);
		}
		dirent_struct = readdir(dirp);
	}
	closedir(dirp);
	return (1);
}

bool	find_matching_files(char *str, char **dir_files, char ***matching_files)
{
	int		i;

	*matching_files = NULL;
	i = 0;
	if (ft_strlen(str) > 1 && str[0] == '.' && str[1] == '/')
		str += 2;
	while (dir_files[i])
	{
		if (is_matching_file(str, dir_files[i]))
			if (!ft_straadd(matching_files, dir_files[i]))
				return (0);
		i++;
	}
	return (1);
}

char	*match_patterns(char *str)
{
	char	**dir_files;
	char	**matching_files;
	char	*new_str;

	if (!get_files_names(&dir_files))
		return (ft_strdup(str));
	if (!find_matching_files(str, dir_files, &matching_files))
	{
		ft_strafree(dir_files);
		return (NULL);
	}
	new_str = create_new_str(str, matching_files);
	ft_strafree(dir_files);
	free(matching_files);
	return (new_str);
}
