/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 14:04:29 by gleal             #+#    #+#             */
/*   Updated: 2021/03/04 21:23:08 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_error(int errornbr)
{
	if (errornbr == MULTIRES)
		printf("multiple resolutions");
	if (errornbr == BADSCREEN)
		printf("invalid screensize!");
	if (errornbr == MULTINO)
		printf("multiple north textures");
	if (errornbr == BADNO)
		printf("can't open north textures");
	if (errornbr == MULTISO)
		printf("multiple south textures");
	if (errornbr == BADSO)
		printf("can't open south textures");
	if (errornbr == MULTIWE)
		printf("multiple west textures");
	if (errornbr == BADWE)
		printf("can't open west textures");
	if (errornbr == MULTIEA)
		printf("multiple east textures");
	if (errornbr == BADEA)
		printf("can't open east textures");
	if (errornbr == MULTISPRITE)
		printf("multiple sprite textures");
	if (errornbr == BADSPRITE)
		printf("can't open sprite textures");
	if (errornbr == MULTIFLOOR)
		printf("multiple floor colors");
	if (errornbr == BADFLOOR)
		printf("invalid floor colors");
	if (errornbr == MULTICEIL)
		printf("multiple ceiling colors");
	if (errornbr == BADCEIL)
		printf("invalid ceiling colors");
	return (0);
}

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
	map->rx = 0;
	map->ry = 0;
	map->error = 0;
	map->no_text = 0;
	map->so_text = 0;
	map->we_text = 0;
	map->ea_text = 0;
	map->sprite_text = 0;
	map->rfloor = 0;
	map->gfloor = 0;
	map->bfloor = 0;
	map->rceil = 0;
	map->gceil = 0;
	map->bceil = 0;
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

int		ft_isspace(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	else
		return (0);
}
