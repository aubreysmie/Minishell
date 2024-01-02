/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhaled <ekhaled@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 21:19:17 by ekhaled           #+#    #+#             */
/*   Updated: 2024/01/02 05:42:16 by ekhaled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "utils.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 100
#endif

static bool	update_buffer(char *dest, char *src, int start_index, int end_index)
{
	char	*new_buffer;
	int		i;

	new_buffer = ft_substrrange(src, start_index, end_index);
	if (!new_buffer)
		return (0);
	ft_strcpy(dest, new_buffer);
	free(new_buffer);
	i = end_index - start_index;
	while (i < BUFFER_SIZE)
	{
		dest[i] = '\0';
		i++;
	}
	return (1);
}

static bool	fill_line(int fd, char **line, int *newline_index)
{
	size_t	bytes_read;
	char	*read_buffer;
	char	*temp_line;

	bytes_read = BUFFER_SIZE;
	while (*newline_index == -1 && bytes_read == BUFFER_SIZE)
	{
		read_buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!read_buffer)
			return (0);
		bytes_read = read(fd, read_buffer, BUFFER_SIZE);
		temp_line = *line;
		*line = ft_strjoin(*line, read_buffer);
		free(read_buffer);
		if (!(*line))
			return (0);
		free(temp_line);
		*newline_index = ft_strchri(*line, '\n');
	}
	return (1);
}

static bool	get_actual_line(char **line_p, char *line,
				char *buffer, int newline_index)
{
	if (ft_strlen(line) == 0)
	{
		free(line);
		line = NULL;
	}
	if (newline_index == -1)
	{
		buffer[0] = 0;
		*line_p = line;
	}
	else
	{
		*line_p = ft_substrrange(line, 0, newline_index);
		if (!(*line_p))
			return (0);
		if (!update_buffer(buffer, line, newline_index + 1, ft_strlen(line)))
			return (0);
		free(line);
	}
	return (1);
}

static bool	get_read_line(char **line_p, int fd, char *buffer)
{
	int		newline_index;
	char	*line;

	line = ft_strdup(buffer);
	if (buffer && !line)
		return (0);
	newline_index = -1;
	if (!fill_line(fd, &line, &newline_index))
	{
		free(line);
		return (0);
	}
	return (get_actual_line(line_p, line, buffer, newline_index));
}

bool	get_next_line(char **line_p, int fd)
{
	static char	buffer[BUFFER_SIZE];
	int			newline_index;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (0);
	newline_index = ft_strchri(buffer, '\n');
	if (newline_index >= 0)
	{
		*line_p = ft_substrrange(buffer, 0, newline_index);
		if (!(*line_p))
			return (0);
		if (!update_buffer(buffer, buffer,
				newline_index + 1, ft_strlen(buffer)))
			return (0);
		return (1);
	}
	return (get_read_line(line_p, fd, buffer));
}
