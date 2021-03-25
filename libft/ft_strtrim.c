/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 18:28:32 by gleal             #+#    #+#             */
/*   Updated: 2021/02/16 19:31:40 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_in_set(char c, char *set)
{
	while (*set)
	{
		if (c == *(set))
			return (1);
		set++;
	}
	return (0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		i;
	char	*str;

	if (!s1 || !set)
		return (0);
	start = 0;
	while (is_in_set(s1[start], (char *)set) && s1[start])
		start++;
	end = ft_strlen(s1);
	while (is_in_set(s1[end - 1], (char *)set) && start < end)
		end--;
	str = malloc(sizeof(char) * (end - start + 1));
	if (!str)
		return (0);
	i = 0;
	while (start < end)
		str[i++] = s1[start++];
	str[i] = '\0';
	return (str);
}
