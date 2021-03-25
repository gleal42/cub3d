/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 17:58:53 by gleal             #+#    #+#             */
/*   Updated: 2021/02/11 22:43:25 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*destn;
	unsigned char	*sourc;
	int				i;

	destn = (unsigned char*)dst;
	sourc = (unsigned char*)src;
	i = len - 1;
	if (sourc < destn)
	{
		while (i >= 0)
		{
			destn[i] = sourc[i];
			i--;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
