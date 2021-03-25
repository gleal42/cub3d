/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 17:36:51 by gleal             #+#    #+#             */
/*   Updated: 2021/02/16 19:31:08 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int		ft_ln_itoa(int n)
{
	int	ln;

	ln = 0;
	if (n <= 0)
		ln++;
	while (n != 0)
	{
		ln++;
		n /= 10;
	}
	return (ln);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		ln;

	ln = ft_ln_itoa(n);
	str = malloc(sizeof(char) * (ln + 1));
	if (!str)
		return (0);
	str[ln] = '\0';
	if (n < 0)
		str[0] = '-';
	else if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		ln--;
		str[ln] = ft_abs(n % 10) + '0';
		n /= 10;
	}
	return (str);
}
