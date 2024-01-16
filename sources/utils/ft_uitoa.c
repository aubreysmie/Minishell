/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 01:13:11 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/16 01:39:50 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

unsigned int	get_array_len(unsigned int n)
{
	unsigned int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

void	fill_array(char *array, unsigned int n, unsigned int len)
{
	unsigned int	i;

	i = len - 1;
	while (i)
	{
		array[i] = n % 10 + '0';
		n /= 10;
		i--;
	}
	array[i] = n % 10 + '0';
	array[len] = 0;
}

char	*ft_uitoa(unsigned int n)
{
	unsigned int	len;
	char			*array;

	len = get_array_len(n);
	array = malloc((len + 1) * sizeof(char));
	if (!array)
		return (NULL);
	fill_array(array, n, len);
	return (array);
}
