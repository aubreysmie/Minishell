/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 17:40:49 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/02 23:08:59 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdbool.h>

void	*ft_calloc(size_t nmemb, size_t size);
int		ft_isalpha(char c);
int		ft_isdigit(char c);
int		ft_isalnum(char c);


int		ft_strlen(const char *str);
char	*ft_strjoin(const char *s1, const char *s2);
int		ft_strchri(const char *str, char c);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strdup(char *str);
char	*ft_substrrange(char *buffer,
			unsigned int start_index, unsigned int end_index);

int		ft_stralen(char **str_array);
char	**ft_stradup(char **str_array);
void	ft_strafree(char **str_array);
bool	ft_straadd(char ***str_array_p, char *new_str);

bool	get_next_line(char **line, int fd);

#endif