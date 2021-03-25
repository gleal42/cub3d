/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 18:03:56 by gleal             #+#    #+#             */
/*   Updated: 2021/01/31 19:34:26 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	ch;
	unsigned char	*string;

	i = 0;
	string = (unsigned char*)s;
	ch = (unsigned char)c;
	while (i < n)
	{
		if (string[i] == ch)
			return (&string[i]);
		i++;
	}
	return (0);
}
