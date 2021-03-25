/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 01:03:42 by gleal             #+#    #+#             */
/*   Updated: 2021/02/08 00:11:33 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
