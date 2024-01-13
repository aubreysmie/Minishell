/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 04:18:39 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/13 04:24:32 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "utils.h"

void	fill_res(const char *s1, const char *s2, char *res)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		res[i + j] = s2[j];
		j++;
	}
	res[i + j] = '\0';
}

char	*ft_strjoinfree(const char *s1, const char *s2)
{
	char	*res;

	if (!s1)
	{
		res = ft_strdup((char *)s2);
		free(s2);
		return (res);
	}
	if (!s2)
	{
		res = ft_strdup((char *)s1);
		free(s1);
		return (res);
	}
	res = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	fill_res(s1, s2, res);
	free(s1);
	free(s2);
	return (res);
}
