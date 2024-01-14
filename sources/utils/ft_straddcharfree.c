/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_straddcharfree.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 18:48:27 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/13 18:52:09 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "utils.h"

char	*ft_straddcharfree(char *s, char c)
{
	unsigned int	i;
	char			*res;

	if (!s)
		return (NULL);
	res = malloc((ft_strlen(s) + 2) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (s[i])
	{
		res[i] = s[i];
		i++;
	}
	res[i] = c;
	res[i + 1] = 0;
	free(s);
	return (res);
}
