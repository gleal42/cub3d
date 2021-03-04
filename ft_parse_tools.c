/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 18:25:12 by gleal             #+#    #+#             */
/*   Updated: 2021/03/04 20:39:18 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_parsespritetext(char *str, t_map *map)
{
	int i;

	i = 1;
	while (ft_isspace(str[i]))
		i++;
	map->sprite_text = ft_strdup(&str[i]);
	if (!map->sprite_text)
		return (0);
	if (open(map->sprite_text, O_RDONLY) < 0)
		return (0);
	return (1);
}

int		ft_parseeasttext(char *str, t_map *map)
{
	int i;

	i = 2;
	while (ft_isspace(str[i]))
		i++;
	map->ea_text = ft_strdup(&str[i]);
	if (!map->ea_text)
		return (0);
	if (open(map->ea_text, O_RDONLY) < 0)
		return (0);
	return (1);
}

int		ft_parsewesttext(char *str, t_map *map)
{
	int i;

	i = 2;
	while (ft_isspace(str[i]))
		i++;
	map->we_text = ft_strdup(&str[i]);
	if (!map->we_text)
		return (0);
	if (open(map->we_text, O_RDONLY) < 0)
		return (0);
	return (1);
}

int		ft_parsesouthtext(char *str, t_map *map)
{
	int i;

	i = 2;
	while (ft_isspace(str[i]))
		i++;
	map->so_text = ft_strdup(&str[i]);
	if (!map->so_text)
		return (0);
	if (open(map->so_text, O_RDONLY) < 0)
		return (0);
	return (1);
}

int		ft_parsenorthtext(char *str, t_map *map)
{
	int i;

	i = 2;
	while (ft_isspace(str[i]))
		i++;
	map->no_text = ft_strdup(&str[i]);
	if (!map->no_text)
		return (0);
	if (open(map->no_text, O_RDONLY) < 0)
		return (0);
	return (1);
}
