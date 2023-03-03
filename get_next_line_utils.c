#include "get_next_line.h"

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
	free((char *)s);
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
