/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 19:08:48 by gleal             #+#    #+#             */
/*   Updated: 2021/02/03 23:25:12 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*string;
	size_t			i;

	string = (unsigned char*)b;
	i = 0;
	while (i < len)
	{
		string[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
