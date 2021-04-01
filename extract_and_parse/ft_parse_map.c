/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 17:36:21 by gleal             #+#    #+#             */
/*   Updated: 2021/04/01 00:05:39 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
/* The way I interpreted a closed map was a map in which the inside of the map is completely
surrounded by walls (including corners), this will is important when doing raycasting to identify if 
there is a wall in that coordinate */
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
/* making sure there is a player in game after parsing the map */
int		playeringame(t_parse *parse)
{
	if (!parse->player_or)
		return (0);
	else
		return (1);
}
/* The first wall can only have spaces and 1s */
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
/* I also do the check for the last wall. In case someone decides to separate the map in 2 one of the halves won't have
a player and it will trigger an error */
int		check_valid_map(char **strs, t_parse *parse)
{
	int		i;

	i = -1;
	while (is_map(strs[++i]))
	{
		parse->nbr_str = i;
		if (i == 0 && !checkwall(strs[i]))
			return (0);
		else if (!is_map(strs[i + 1]))
		{
			if (i < 2)
				return (0);
			if (!playeringame(parse))
				return (0);
		}
		else
		{
			if (!checkmapclosed(&strs[i]) ||
				!checkmultiplayer(strs[i], parse))
				return (0);
		}
	}
	if (!ft_copy_map(strs, parse))
		return (0);
	return (1);
}
