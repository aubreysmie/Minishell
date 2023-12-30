/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 17:40:49 by ekhaled           #+#    #+#             */
/*   Updated: 2023/12/30 03:06:58 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdbool.h>

int		ft_strlen(char *str);
int		ft_stralen(char **str_array);
char	**ft_stradup(char **str_array);
void	ft_strafree(char **str_array);
bool	ft_straadd(char ***str_array_p, char *new_str);

#endif