#include "get_next_line.h"

char	*ft_strjoin(char *s1, char const *s2, char **s3)

{
	char	*ret;
	int		n;
	int len;
	if (!s1)
		s1 = strdup("");
	if (!s1)
		return (NULL);
	len = strlen(s1);
	n = -1;
	if (*s1 == '\0' && *s2 == '\0')
	{
		free((void *)s1);
		return (strdup(""));
	}
	ret = (char *)calloc(strlen(s1) + strlen(s2) + 1, sizeof(char));
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
    free(*s3);
	while (*s2 != '\0')
	{
		n++;
		ret[n] = *s2;
		s2++;
	}
	s1 = s1 - len;
	return (ret);
}

void ft_memsetc(char **str, int start, int len)
{
    if ((size_t)start >= strlen(*str))
        return;
    while (start < len)
    {
        *str[start] = '\0';
        start++;
    }
}