/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltranca- <ltranca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:47:01 by ltranca-          #+#    #+#             */
/*   Updated: 2023/01/27 17:58:49 by ltranca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	char *buffer;
	char *buffer_buffer;
	static char *next;
	int len;

	if (fd < 0)
		return (NULL);
	buffer_buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer_buffer)
		return(NULL);
	if (next && ft_strlen(next) > 0)
	{
		buffer = ft_strdup(next);
		if (!buffer)
		{
			free(buffer_buffer);
			return (NULL);
		}
	}
	else 
	{
		buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!buffer)
		{
			free(buffer_buffer);
			return (NULL);
		}
		if (read(fd, buffer, BUFFER_SIZE) == -1 && !next)
		{
			free(buffer_buffer);
			free(buffer);
			return(NULL);
		}
		if (ft_strlen(buffer) == 0)
		{
			free(buffer_buffer);
			free(buffer);
			return(NULL);
		}
	}
	while (1)
	{
		if (ft_strchr(buffer, '\n') != 0)
		{
			if (next)
				free(next);
			next = ft_strdup(ft_strchr(buffer, '\n'));
			if (!next)
			{
				free(buffer_buffer);
				free(buffer);
				return(NULL);
			}
			len = ft_strlen(buffer) - ft_strlen(next);
			buffer = ft_substr(buffer, 0, len);
			break;
		}
		if (!read(fd, buffer_buffer, BUFFER_SIZE))
			break;
		buffer = ft_strjoin(buffer, buffer_buffer);
		if (!buffer)
		{
			free(buffer_buffer);
			free(buffer);
			return (NULL);
		}
	}
	if (ft_strlen(buffer) == 0)
	{
		free(buffer_buffer);
		free(buffer);
		return(NULL);
	}
	free(buffer_buffer);
	return (buffer);
}