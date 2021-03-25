/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 18:43:55 by gleal             #+#    #+#             */
/*   Updated: 2021/02/18 16:12:35 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	*res;

	str = (char *)s;
	res = 0;
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == (char)c)
			res = str;
		str++;
	}
	if (*str == (char)c)
		res = str;
	return (res);
}
