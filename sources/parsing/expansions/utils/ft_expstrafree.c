/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expstrafree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 13:49:30 by ekhaled           #+#    #+#             */
/*   Updated: 2024/02/04 13:50:13 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_expstrafree(t_exp_str_array exp_str_array)
{
	int	i;

	i = 0;
	while (i < exp_str_array.len)
	{
		free(exp_str_array.array[i].range_array.array);
		free(exp_str_array.array[i].str);
		i++;
	}
	free(exp_str_array.array);
}
