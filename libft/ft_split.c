/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 23:26:13 by gleal             #+#    #+#             */
/*   Updated: 2021/02/16 16:42:02 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_freestrs(char **strs, size_t prev)
{
	size_t	i;

	i = 0;
	while (i < prev)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (0);
}

size_t	ft_len(char *str, char c)
{
	int	count;

	count = 0;
	while (*str != c && *str)
	{
		str++;
		count++;
	}
	return (count);
}

size_t	ft_wordnr(char *str, char del)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str == del && *str)
			str++;
		if (*str != del && *str)
		{
			count++;
			while (*str != del && *str)
				str++;
		}
	}
	return (count);
}

void	*ft_put_strings(char **new, char *str, char c)
{
	size_t	ptr;
	size_t	i;

	i = 0;
	ptr = 0;
	while (str[ptr])
	{
		while (str[ptr] == c && str[ptr])
			ptr++;
		if (str[ptr] != c && str[ptr])
		{
			new[i] = ft_substr(str, ptr, ft_len(&(str[ptr]), c));
			if (!new[i])
				return (ft_freestrs(new, i));
			while (str[ptr] != c && str[ptr])
				ptr++;
			i++;
		}
	}
	new[i] = 0;
	return (new);
}

char	**ft_split(char const *s, char c)
{
	char	**new;
	char	*str;
	int		words;

	str = (char *)s;
	if (!s)
		return (0);
	words = ft_wordnr(str, c);
	new = malloc(sizeof(char*) * (words + 1));
	if (!new)
		return (0);
	ft_put_strings(new, str, c);
	return (new);
}
