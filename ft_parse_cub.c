/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_cub.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 20:01:55 by gleal             #+#    #+#             */
/*   Updated: 2021/03/03 21:50:16 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_screensize(char *str, t_map *map)
{
	if ()
}
int		is_map(char *str)
{
	if (ft_strchr(str, '1'))
	{
		while (*str)
		{
			if(!ft_strchr(" 012NSEW", *str))
				return(0);
		}
	}
	else
		return (0);
	return (1);
}

void	ft_parse_cub(char **text, t_map *map)
{
	int		i;

	i = 0;
	while (!is_map(text[i]))
	{
		if (text[i][0] == 'R')
		{
			if(!ft_screensize(text[i], map))
				return (-1);
		}
	}
}
