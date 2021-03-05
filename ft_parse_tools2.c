/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_tools2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 18:58:48 by gleal             #+#    #+#             */
/*   Updated: 2021/03/05 21:25:24 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_valid_map(char **strs, t_map *map)
{
	int		i;

	i = 0;
	while (is_map(strs[i]))
	{
		if (i == 0)
		{
			if (!checkwall(strs[i]))
					return (0);
		}
		else if (!is_map(strs[i + 1]))
		{
			if (i < 2)
				return (0);
			if (!playeringame(map))
				return (0);
		}
		else
		{
			if (!checkfirstwall(strs[i]))
				return (0);
			if (!checkmapclosed(&strs[i]))
				return (0);
			if (!checkmultiplayer(strs[i], map))
				return (0);
		}
		i++;
	}
	map->map_size = i;
	if (!ft_copy_map(strs, map))
		return (0);
	return (1);
}

int		is_map(char *str)
{
	if(*str == '\0')
		return (0);
	while (*str)
	{
		if (!ft_isspace(*str) && !ft_strchr(MAP_CHARS, *str))
			return (0);
		str++;
	}
	return (1);
}

int		ft_parseceilcolor(char *str, t_map *map)
{
	int		i;

	i = 1;
	while (ft_isspace(str[i]) || str[i] == ',')
		i++;
	if (!isdigit(str[i]))
		return (0);
	map->rceil = ft_atoi(&str[i]);
	while (ft_isdigit(str[i]))
		i++;
	while (ft_isspace(str[i]) || str[i] == ',')
		i++;
	if (!isdigit(str[i]))
		return (0);
	map->gceil = ft_atoi(&str[i]);
	while (ft_isdigit(str[i]))
		i++;
	while (ft_isspace(str[i])  || str[i] == ',')
		i++;
	if (!isdigit(str[i]))
		return (0);
	map->bceil = ft_atoi(&str[i]);
	if (map->rceil < 0 || map-> rceil > 255)
		return (0);
	if (map->gceil < 0 || map-> gceil > 255)
		return (0);
	if (map->bceil < 0 || map-> bceil > 255)
		return (0);
	return (1);
}

int		ft_parsefloorcolor(char *str, t_map *map)
{
	int		i;

	i = 1;
	while (ft_isspace(str[i]) || str[i] == ',')
		i++;
	if (!isdigit(str[i]))
		return (0);
	map->rfloor = ft_atoi(&str[i]);
	while (ft_isdigit(str[i]))
		i++;
	while (ft_isspace(str[i]) || str[i] == ',')
		i++;
	if (!isdigit(str[i]))
		return (0);
	map->gfloor = ft_atoi(&str[i]);
	while (ft_isdigit(str[i]))
		i++;
	while (ft_isspace(str[i])  || str[i] == ',')
		i++;
	if (!isdigit(str[i]))
		return (0);
	map->bfloor = ft_atoi(&str[i]);
	if (map->rfloor < 0 || map-> rfloor > 255)
		return (0);
	if (map->gfloor < 0 || map-> gfloor > 255)
		return (0);
	if (map->bfloor < 0 || map-> bfloor > 255)
		return (0);
	return (1);
}
