/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expstrdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 13:54:39 by ekhaled           #+#    #+#             */
/*   Updated: 2024/02/04 14:02:03 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_exp_str	ft_expstrdup(t_exp_str exp_str)
{
	t_exp_str	dup;

	dup.is_expanded = exp_str.is_expanded;
	dup.range_array = ft_rangearraydup(exp_str.range_array);
	dup.str = ft_strdup(exp_str.str);
	return (dup);
}
