/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 01:34:43 by gleal             #+#    #+#             */
/*   Updated: 2021/01/29 03:14:50 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*destn;
	unsigned char	*sourc;
	unsigned char	ch;
	size_t			i;

	destn = (unsigned char*)dst;
	sourc = (unsigned char*)src;
	ch = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		destn[i] = sourc[i];
		if (destn[i] == ch)
			return (&dst[i + 1]);
		i++;
	}
	return (0);
}
