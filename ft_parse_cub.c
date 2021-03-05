/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_cub.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 20:01:55 by gleal             #+#    #+#             */
/*   Updated: 2021/03/05 21:46:08 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_screensize(char *str, t_map *map)
{
	int		i;

	i = 1;
	while (ft_isspace(str[i]))
		i++;
	map->rx = ft_atoi(&str[i]);
	while (ft_isdigit(str[i]))
		i++;
	while (ft_isspace(str[i]))
		i++;
	map->ry = ft_atoi(&str[i]);
	if (map->rx <= 0 || map->ry <= 0 || map->rx > MAX_X_SIZE || map->ry > MAX_Y_SIZE)
		return (0);
	return (1);
}

int		ft_parse_cub(char **text, t_map *map)
{
	int		i;

	i = 0;
	while (text[i])
	{
		if (text[i][0] == 'R')
		{
			if (map->rx || map->ry)
				return (ft_error(MULTIRES));
			if(!ft_screensize(text[i], map))
				return (ft_error(BADSCREEN));
		}
		else if (text[i][0] == 'N' && text[i][1] == 'O')
		{
			if (map->no_text)
				return (ft_error(MULTINO));
			if (!ft_parsenorthtext(text[i], map))
				return (ft_error(BADNO));
		}
		else if (text[i][0] == 'S' && text[i][1] == 'O')
		{
			if (map->so_text)
				return (ft_error(MULTISO));
			if (!ft_parsesouthtext(text[i], map))
				return (ft_error(BADSO));
		}
		else if (text[i][0] == 'W' && text[i][1] == 'E')
		{
			if (map->we_text)
				return (ft_error(MULTIWE));
			if (!ft_parsewesttext(text[i], map))
				return (ft_error(BADWE));
		}
		else if (text[i][0] == 'E' && text[i][1] == 'A')
		{
			if (map->ea_text)
				return (ft_error(MULTIEA));
			if (!ft_parseeasttext(text[i], map))
				return (ft_error(BADEA));
		}
		else if (text[i][0] == 'S' && text[i][1] != 'O')
		{
			if (map->sprite_text)
				return (ft_error(MULTISPRITE));
			if (!ft_parsespritetext(text[i], map))
				return (ft_error(BADSPRITE));
		}
		else if (text[i][0] == 'F')
		{
			if (map->rfloor || map->gfloor || map->bfloor)
				return (ft_error(MULTIFLOOR));
			if (!ft_parsefloorcolor(text[i], map))
				return (ft_error(BADFLOOR));
		}
		else if (text[i][0] == 'C')
		{
			if (map->rceil || map->gceil || map->bceil)
				return (ft_error(MULTICEIL));
			if (!ft_parseceilcolor(text[i], map))
				return (ft_error(BADCEIL));
		}
		else if (is_map(text[i]))
		{
			if(!check_valid_map(&text[i], map))
				return (ft_error(INVALIDMAP));
			while (is_map(text[i + 1]) && text[i])
				i++;
		}
		else if (text[i][0] != '\0')
			return (ft_error(INVALIDCHAR));
		i++;
	}
	free_all_strs(map->text);
	return (1);
}
