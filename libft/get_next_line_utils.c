/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 22:17:48 by gleal             #+#    #+#             */
/*   Updated: 2021/02/18 14:34:54 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str)
	{
		if (*str == (char)c)
			return (str);
		str++;
	}
	if (*str == (char)c)
		return (str);
	return (0);
}

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	size;
	char	*str;

	size = 0;
	while (s1[size])
		size++;
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (0);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	count;
	size_t	j;

	if (!s1 || !s2)
		return (0);
	count = ft_strlen(s1) + ft_strlen(s2);
	j = 0;
	if (!count)
		return (0);
	str = (char *)malloc(sizeof(char) * (count + 1));
	if (!str)
		return (0);
	while (*s1)
		str[j++] = *(s1++);
	while (*s2)
		str[j++] = *(s2++);
	str[j] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;
	size_t	length;

	length = len;
	i = 0;
	if (!s)
		return (0);
	if (ft_strlen(s) - start <= length)
		length = ft_strlen(s) - start;
	if (ft_strlen(s) <= start)
	{
		start = 0;
		length = 0;
	}
	str = (char *)malloc(sizeof(char) * (length + 1));
	if (!str)
		return (0);
	while (s[start] && length--)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
