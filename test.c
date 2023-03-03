# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <string.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	(int)1024
# endif
size_t	ft_strlen(const char *a)

{
	size_t	n;
	if (!a)
		return(0);

	n = 0;
	while (*a)
	{
		n++;
		a++;
	}
	return (n);
}

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	size_t	n;
	char	*buff;
	char	*buff2;

	n = 0;
	buff = (char *)dest;
	buff2 = (char *)src;
	if (buff != NULL || buff2 != NULL)
	{
		while (n < size)
		{
			buff[n] = buff2[n];
			n++;
		}
	}
	return (dest);
}

char	*ft_strdup(const char *s1)
{
	int		n;
	char	*ret;
	if (!s1)
		return(NULL);
    n = 0;
    while (s1[n] != '\0')
    {
        n++;
    }
    ret = malloc((n + 1) * sizeof(char));
	if (!ret)
		return (0);
	ret = ft_memcpy(ret, s1, n + 1);
	return (ret);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)

{
	size_t	len;

	len = ft_strlen(src);
	if (len + 1 < size)
		ft_memcpy(dest, src, len + 1);
	else if (size != 0)
	{
		ft_memcpy(dest, src, size - 1);
		dest[size - 1] = '\0';
	}
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*a;
	int index;

	index = len+1;
	if (start >= ft_strlen(s))
	{
		free((void *)s);
		return (ft_strdup(""));
	}
	if (ft_strlen(&s[start]) < len)
		len = ft_strlen(&s[start]);
	a = calloc(len + 1, sizeof(char));
	if (!a)
	{
		free((void *)s);
		return (0);
	}
	ft_strlcpy(a, &s[start], len + (size_t)1);
	return (a);
}

char	*ft_strjoin(char *s1, char const *s2)

{
	char	*ret;
	int		n;
	int len;
	if (!s1)
		s1 = ft_strdup("");
	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	n = -1;
	if (*s1 == '\0' && *s2 == '\0')
	{
		free((void *)s1);
		return (ft_strdup(""));
	}
	ret = calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!ret)
	{
		free((void *)s1);
		return (0);
	}
	while (*s1 != '\0')
	{
		n++;
		ret[n] = *s1;
		s1++;
	}
	while (*s2 != '\0')
	{
		n++;
		ret[n] = *s2;
		s2++;
	}
	s1 = s1 - len;
	return (ret);
}

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
		free(rest);
		if (!ret)
		{
			free(rest);
			return(NULL);
		}
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
			if (rest)
				free(rest);
			//printf("(%s %i %lu)", ret, diff_size, ft_strlen(ret));
            rest = ft_substr(ret, (ft_strlen(ret) - diff_size), diff_size);
            if (!rest)
            {
                free(buffer);
                free(ret);
                return(NULL);
            }
			if (buffer)
				free(buffer);
			buffer = ft_strdup(ret);
			if (!buffer)
			{
				free(ret);
				free(rest);
				return(NULL);
			}
			free(ret);
            ret = ft_substr(buffer, 0, (ft_strlen(buffer) - diff_size + 1));
            break;
        }
        if (!read(fd, buffer, BUFFER_SIZE))
            break;
		if (rest)
			free(rest);
		rest = ft_strdup(ret);
		if (!rest)
		{
			free(ret);
			free(buffer);
			return(NULL);
		}
		free(ret);
        ret = ft_strjoin(rest, buffer);
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

int main()
{
    int fd = open("example.txt", O_RDONLY);
    printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
}