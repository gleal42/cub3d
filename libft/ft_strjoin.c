/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 17:26:57 by gleal             #+#    #+#             */
/*   Updated: 2021/02/16 16:33:18 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	count;
	size_t	j;

	if (!s1 || !s2)
		return (0);
	count = ft_strlen(s1) + ft_strlen(s2);
	j = 0;
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
