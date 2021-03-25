/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 19:30:37 by gleal             #+#    #+#             */
/*   Updated: 2021/02/11 22:39:56 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*s1;
	char	*s2;
	size_t	i;
	size_t	j;

	s1 = (char *)haystack;
	s2 = (char *)needle;
	i = 0;
	if (!*s2)
		return (s1);
	while (i < len && s1[i])
	{
		j = 0;
		while (i + j < len && s1[i + j] && s2[j] && s1[i + j] == s2[j])
			j++;
		if (s2[j] == '\0')
			return (&s1[i]);
		i++;
	}
	return (0);
}
