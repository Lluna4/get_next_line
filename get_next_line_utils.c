/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltranca- <ltranca-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:45:25 by ltranca-          #+#    #+#             */
/*   Updated: 2023/01/18 15:23:04 by ltranca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
size_t	ft_strlen(const char *a)

{
	size_t	n;

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

void	ft_bzero(void *a, size_t size)
{
	size_t	n;
	char	*b;

	b = (char *)a;
	n = 0;
	while (n <= size - 1)
	{
		if (size <= 0)
			break ;
		b[n] = '\0';
		n++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret;

	ret = (void *)malloc(count * size);
	if (!ret)
		return (0);
	ft_bzero(ret, size * count);
	return (ret);
}

char	*ft_strdup(const char *s1)

{
	int		n;
	char	*ret;

	n = ft_strlen(s1);
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
		return (ft_strdup(""));
	if (ft_strlen(&s[start]) < len)
		len = ft_strlen(&s[start]);
	a = ft_calloc(len + 1, sizeof(char));
	if (!a)
		return (0);
	ft_strlcpy(a, &s[start], len + (size_t)1);
	return (a);
}	

char	*ft_strjoin(char const *s1, char const *s2)

{
	char	*ret;
	int		n;

	n = -1;
	if (*s1 == '\0' && *s2 == '\0')
		return (ft_strdup(""));
	ret = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!ret)
		return (0);
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
	return (ret);
}