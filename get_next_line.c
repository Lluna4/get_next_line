#include "get_next_line.h"

static int ft_check(char *s)
{
    int ret;
    
    ret = 0;
    while (*s)
    {
        if (*s == '\n')
        {
            while (*s)
            {
                s++;
                ret++;
            }
            if (ret == 0)
                ret = 1;
            return (ret);
        }
        s++;
    }
    return(0);
}

char    *get_next_line(int fd)
{
    char *buffer;
    static char *rest;
    char *ret;
    int diff_size;

    if (fd < 0)
        return(NULL);
    if (rest)
	{
        ret = ft_strdup(rest);
		ret++;
	}
    else
    {
        ret = malloc((BUFFER_SIZE + 1) * sizeof(char));
        if (read(fd, ret, BUFFER_SIZE) == -1)
        {
            free(ret);
            return(NULL);
        }
    }
    if (!ret)
        return (NULL);
    buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!buffer)
    {
        free(ret);
        return(NULL);
    }
    while (1)
    {
        if (ft_check(ret) == 1)
            break;
        if (ft_check(ret) > 1)
        {
            diff_size = ft_check(ret);
            rest = malloc((diff_size + 1) * sizeof(char));
			//printf("(%s %i %lu)", ret, diff_size, ft_strlen(ret));
            rest = ft_substr(ret, (ft_strlen(ret) - diff_size), diff_size);
            if (!rest)
            {
                free(buffer);
                free(ret);
                return(NULL);
            }
            ret = ft_substr(ret, 0, (ft_strlen(ret) - diff_size + 1));
            break;
        }
        if (!read(fd, buffer, BUFFER_SIZE))
            break;
        ret = ft_strjoin(ret, buffer);
    }
    free(buffer);
    if (!ret)
    {
        if (rest)
            free(rest);
        return(NULL);
    }
    ret[ft_strlen(ret)] = '\0';
    return(ret);
}