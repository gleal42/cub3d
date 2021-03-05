/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_tools3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 15:32:05 by gleal             #+#    #+#             */
/*   Updated: 2021/03/05 20:57:48 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_all_sides(char **strs, int j)
{
	if (ft_isspace(strs[-1][j - 1]) || !strs[-1][j - 1])
		return (0);
	if (ft_isspace(strs[-1][j]) || !strs[-1][j])
		return (0);
	if (ft_isspace(strs[-1][j + 1]) || !strs[-1][j + 1])
		return (0);
	if (ft_isspace(strs[0][j - 1]) || !strs[0][j - 1])
		return (0);
	if (ft_isspace(strs[0][j + 1]) || !strs[0][j + 1])
		return (0);
	if (ft_isspace(strs[1][j - 1]) || !strs[1][j - 1])
		return (0);
	if (ft_isspace(strs[1][j]) || !strs[1][j])
		return (0);
	if (ft_isspace(strs[1][j + 1]) || !strs[1][j + 1])
		return (0);
	return (1);
}

int		checkmapclosed(char **strs)
{
	int j;

	j = 0;
	while (strs[0][j])
	{
		if (ft_strchr(MAP_INSIDE, strs[0][j]))
		{
			if (!check_all_sides(strs, j))
				return (0);
		}
		j++;
	}
	return (1);
}

int		checkfirstwall(char *str)
{
	while (ft_isspace(*str))
		str++;
	if (*str != '1')
		return (0);
	return (1);
}

int		playeringame(t_map *map)
{
	if (!map->player_or)
		return (0);
	else
		return (1);
}

int		checkwall(char *str)
{
	while (*str)
	{
		if (*str != '1' && !ft_isspace(*str))
				return (0);
		str++;
	}
	return (1);
}
