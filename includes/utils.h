/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 17:40:49 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/27 23:50:05 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdbool.h>
# include <stdlib.h>

typedef struct s_lstr	t_lstr;

int				ft_max(int a, int b);
int				ft_min(int a, int b);

unsigned int	ft_atoui(char *nptr);
char			*ft_uitoa(unsigned int n);
void			*ft_calloc(size_t nmemb, size_t size);
int				ft_isalpha(char c);
int				ft_isdigit(char c);
int				ft_isalnum(char c);
bool			ft_strisnum(char *str);

int				ft_strlen(const char *str);
int				ft_strcmp(const char *s1, const char *s2);
bool			ft_strareeq(char *s1, char *s2);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_strjoinfree(const char *s1, const char *s2);
int				ft_strchri(const char *str, char c);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strdup(char *str);
char			**ft_split(char const *s, char c);
char			**ft_splitset(char const *s, char set[]);
char			*ft_substrrange(char *buffer,
					unsigned int start_index, unsigned int end_index);
bool			ft_strisinstr(char *str_to_find, char *str_to_search);

bool			ft_charisinset(char c, char set[]);
bool			ft_charsetisinlstr(char set[], t_lstr lstr);
bool			ft_strareeq(char *s1, char *s2);
int				ft_strchrseti(const char *str, char set[]);
int				ft_lstrchrseti(t_lstr lstr, char set[]);
int				ft_lstrcmp(t_lstr s1, t_lstr s2);

int				ft_stralen(char **str_array);
char			**ft_stradup(char **str_array);
char			*ft_strajoin(char **str_array);
char			*ft_strajoinfree(char **str_array);
void			ft_strafree(char **str_array);
bool			ft_straadd(char ***str_array_p, char *str);
char			*ft_straddcharfree(char *s, char c);
bool			ft_strarm(char ***str_array_p, char *str);
bool			ft_strarp(char **str_array, char *old_str, char *new_str);
bool			ft_strisinstra(char *str, char **str_array);

bool			get_next_line(char **line, int fd);

#endif