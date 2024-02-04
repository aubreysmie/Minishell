/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_new_stra.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:11:14 by ekhaled           #+#    #+#             */
/*   Updated: 2024/02/03 15:36:15 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**create_unexpanded_stra(char *str)
{
	char	**new_stra;

	new_stra = malloc(2 * sizeof(char *));
	if (!new_stra)
		return (NULL);
	new_stra[0] = str;
	new_stra[1] = NULL;
	return (new_stra);
}

char	**create_prefixed_stra(char **matching_files)
{
	unsigned int	i;
	unsigned int	len;
	char			**new_stra;

	i = 0;
	len = ft_stralen(matching_files);
	new_stra = malloc((len + 1) * sizeof(char *));
	if (!new_stra)
		return (NULL);
	while (matching_files[i])
	{
		new_stra[i] = ft_strjoin("./", matching_files[i]);
		if (!new_stra[i])
			return (ft_free_words(new_stra, i), NULL);
		i++;
	}
	new_stra[i] = NULL;
	return (new_stra);
}

char	**create_unprefixed_stra(char **matching_files)
{
	unsigned int	i;
	unsigned int	len;
	char			**new_stra;

	i = 0;
	len = ft_stralen(matching_files);
	new_stra = malloc((len + 1) * sizeof(char *));
	if (!new_stra)
		return (NULL);
	while (matching_files[i])
	{
		new_stra[i] = ft_strdup(matching_files[i]);
		if (!new_stra[i])
			return (ft_free_words(new_stra, i), NULL);
		i++;
	}
	new_stra[i] = NULL;
	return (new_stra);
}

char	**create_new_stra(char *str, char **matching_files)
{
	if (!matching_files)
		return (create_unexpanded_stra(str));
	if (ft_strlen(str) > 1
		&& str[0] == '.' && str[1] == '/')
		return (create_prefixed_stra(matching_files));
	else
		return (create_unprefixed_stra(matching_files));
}
