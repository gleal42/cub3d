/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 17:36:21 by gleal             #+#    #+#             */
/*   Updated: 2021/03/29 19:16:16 by gleal            ###   ########.fr       */
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

int		playeringame(t_parse *parse)
{
	if (!parse->player_or)
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
