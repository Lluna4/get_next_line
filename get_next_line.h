#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	(int)1024
# endif
// funciones aqui
size_t	ft_strlen(const char *a);
void	*ft_memcpy(void *dest, const void *src, size_t size);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char    *get_next_line(int fd);
#endif