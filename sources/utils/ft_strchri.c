/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 23:21:37 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/12 18:32:55 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strchri(const char *str, char c)
{
	int	i;

	if (!str)
		return (-2);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	if (str[i] == c)
		return (i);
	return (-1);
}
