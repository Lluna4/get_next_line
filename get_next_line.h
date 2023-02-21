/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltranca- <ltranca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:51:17 by ltranca-          #+#    #+#             */
/*   Updated: 2023/02/21 16:14:16 by ltranca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	(int)1024
# endif

size_t	ft_strlen(const char *a);
void	*ft_memcpy(void *dest, const void *src, size_t size);
void	ft_bzero(void *a, size_t size);
void    *ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_memchr(const void *s, int c, size_t size);
char	*ft_strchr(const char *a, int ch);
char	*ft_strjoin(char *s1, char const *s2);
int	    ft_strncmp(const char *a, const char *b, int ch);
char	**ft_split(char const *s, char c);
char    *get_next_line(int fd);


#endif