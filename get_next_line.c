/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltranca- <ltranca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:47:01 by ltranca-          #+#    #+#             */
/*   Updated: 2023/01/18 15:26:31 by ltranca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	char *buffer;
	char *buffer_buffer;
	static char *next;
	int len;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	buffer_buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (next)
		buffer = next;
	else 
	{
		if (!read(fd, buffer, BUFFER_SIZE) && !next)
		{
			free(buffer);
			free(buffer_buffer);
			return(NULL);
		}
	}
	while (1)
	{
		if (ft_strchr(buffer, '\n') != 0)
		{
			if (ft_strchr(buffer, '\n') != 0)
			{
				next = ft_strdup(ft_strchr(buffer, '\n'));
				len = ft_strlen(buffer) - ft_strlen(next);
				buffer = ft_substr(buffer, 0, len);
				break;
			}
			else
			{
				break;
			}
		}
		read(fd, buffer_buffer, BUFFER_SIZE);
		buffer = ft_strjoin(buffer, buffer_buffer);
	}
	return (buffer);
}