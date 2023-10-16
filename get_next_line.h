#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <string.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	(int)1
# endif
//structs
struct linked_list
{
    char *data;
    struct linked_list *next;
};



// funciones aqui
char	*ft_strjoin(char *s1, char const *s2, char **s3);
void ft_memsetc(char **str, int start, int len);
char    *get_next_line(int fd);
#endif