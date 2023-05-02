#include "get_next_line.h"

char *ft_nl_test(char *buff, char **sobras)
{
    int index;
    char *ret;

    index = 0;
    while (buff[index])
    {
        if (buff[index] == '\n')
        {
            ret = malloc(index * sizeof(char) + 1);
            if (!ret)
            {
                free(buff);
                free(*sobras);
                return(NULL);
            }
            ft_memcpy(ret, buff, index * sizeof(char));
            ft_memcpy(*sobras, buff, ft_strlen(buff+index));
            free(buff);
            ret[BUFFER_SIZE] = '\0';
            return(ret);
        }
        index++;
    }
    return (NULL);
}

char    *get_next_line(int fd)
{
    static char *sobras;
    char *ret;
    char *buff;
    int index;

    if (sobras != NULL)
        ft_memcpy(buff, sobras, sizeof(sobras));
    else
    {
        buff = malloc(BUFFER_SIZE * sizeof(char) + 1);
        if (!buff)
            return(NULL);
        if (read(fd, buff, BUFFER_SIZE) == -1)
        {
            free(buff);
            return (NULL);
        }
        sobras = malloc(BUFFER_SIZE * sizeof(char) + 1);
    }   
    index = 0;
    //Comprueba si hay salto de linea
    ret = malloc(index * sizeof(char) + 1);
    ft_memcpy(ret, ft_nl_test(buff, &sobras), BUFFER_SIZE);
    if (ret != NULL)
    {
        ret[BUFFER_SIZE] = '\0';
        return(ret);
    }
    free(ret);
    ret = malloc(index * sizeof(char) + 1);
    while (1)
    {
        ft_memcpy(ret, buff, BUFFER_SIZE + 1);
        if (!read(fd, buff, BUFFER_SIZE + 1))
        {
            free(buff);
            free(sobras);
            return(NULL);
        }
        ft_memcpy(ret, ft_nl_test(buff, &sobras), BUFFER_SIZE);
        if (ret != NULL)
        {
        ret[BUFFER_SIZE] = '\0';
        return(ret);
        }
        ret = ft_strjoin(ret, buff);
    }
}