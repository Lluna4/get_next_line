/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltranca- <ltranca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:47:01 by ltranca-          #+#    #+#             */
/*   Updated: 2023/02/21 17:01:02 by ltranca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *free_all(char **buffer_buffer, char **buffer)
{
	free(*buffer_buffer);
	free(*buffer);
	*buffer = NULL;
	*buffer_buffer = NULL;
	return(NULL);
}
static int mat2d_len(char **mat)
{
	int len;

	len = 0;
	while (mat[len])
		len++;
	return(len);
}

static int  mat2d_charlen(char **mat)
{
	int len;
	int y;

	len = 0;
	y = 0;
	while(mat[y])
	{
		len += ft_strlen(mat[y]);
		y++;
	}
	return(len);
}

char *get_next_line(int fd)
{
	char *buffer;
	char *buf;
	char **buffer_buffer;
	static char *next;
	int len;
	int index;
	
	if (fd < 0)
		return (NULL);
	if (next && ft_strlen(next) > 1)
	{
		buffer = ft_strdup(next);
		if (!buffer)
			return(NULL);
	}
	else
	{
		buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!buffer)
			return(NULL);
		if (read(fd, buffer, BUFFER_SIZE) == -1)
			{
				free(buffer);
				return(NULL);
			}
	}
	buffer_buffer = ft_split(buffer, '\n');
	if (!buffer_buffer)
	{
		buf = ft_calloc(BUFFER_SIZE, sizeof(char));
		while (1)
		{
			if (ft_strchr(buffer, '\n') != 0)
				break;
			if (!read(fd, buf, BUFFER_SIZE))
			{
				return(free_all(&buf, &buffer));
			}
			buffer = ft_strjoin(buffer, buf);
		}
	}
	else
	{
		buffer =  buffer_buffer[0];
		len = mat2d_len(buffer_buffer);
		index = 1;
		buffer++;
		next = ft_calloc(mat2d_charlen(&buffer), sizeof(char));
		next = ft_strdup(&buffer[index]);
		while (buffer[index])
		{
			next = ft_strjoin(next, &buffer[index]);
			index++;
		}
		buffer--;
	}
	return(&buffer[0]);
}