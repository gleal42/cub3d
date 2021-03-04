/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 14:04:29 by gleal             #+#    #+#             */
/*   Updated: 2021/03/03 19:56:03 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*ft_freetext(char **text)
{
	size_t	i;

	i = 0;
	while (text[i])
	{
		free(text[i]);
		i++;
	}
	free(text);
	return (0);
}

void	ft_start_tmap(t_map *map)
{
	map->lnbr = 0;
	map->text = malloc(sizeof(char *) * 2);
	if (!map->text)
		return ;
	map->text[0] = 0;
	map->text[1] = 0;
}

int		ft_countchr(char *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str == c)
			count++;
		str++;
	}
	return (count);
}

