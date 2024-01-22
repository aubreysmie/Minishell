/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_new_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 23:33:54 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/20 23:50:26 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*create_prefixed_str(char **matching_files)
{
	int		i;
	char	*new_str;
	char	*temp;

	i = 1;
	new_str = ft_strjoin("./", matching_files[0]);
	if (!new_str)
		return (NULL);
	while (matching_files[i])
	{
		temp = new_str;
		new_str = ft_strajoin((char *[]){new_str, " ", "./",
				matching_files[i], NULL});
		free(temp);
		if (!new_str)
			return (NULL);
		i++;
	}
	return (new_str);
}

char	*create_unprefixed_str(char **matching_files)
{
	int		i;
	char	*new_str;
	char	*temp;

	i = 1;
	new_str = ft_strdup(matching_files[0]);
	if (!new_str)
		return (NULL);
	while (matching_files[i])
	{
		temp = new_str;
		new_str = ft_strajoin((char *[]){new_str, " ",
				matching_files[i], NULL});
		free(temp);
		if (!new_str)
			return (NULL);
		i++;
	}
	return (new_str);
}

char	*create_new_str(char *str, char **matching_files)
{
	char	*new_str;

	if (!matching_files)
		return (ft_strdup(str));
	if (ft_strlen(str) > 1
		&& str[0] == '.' && str[1] == '/')
		new_str = create_prefixed_str(matching_files);
	else
		new_str = create_unprefixed_str(matching_files);
	return (new_str);
}
