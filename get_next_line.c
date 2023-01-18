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
	char		*buffer;
    static char *line;
	int index;
    
	index = 0;
	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return(NULL);
	read(fd, buffer, BUFFER_SIZE);
    //printf("%s", buffer);
    line = ft_strdup(buffer);
	while (buffer[index] != '\n' && buffer[index] != '\0')
		index++;
    line = line + index;
	free(buffer);
	return(line);
}