/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 14:04:29 by gleal             #+#    #+#             */
/*   Updated: 2021/03/19 21:35:14 by gleal            ###   ########.fr       */
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
	if (errornbr == INVALIDMAP)
		printf("invalid map");
	if (errornbr == INVALIDCHAR)
		printf("invalid character in cub text");
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

void	ft_start_tmap(t_parse *parse)
{
	parse->lnbr = 0;
	parse->text = malloc(sizeof(char *) * 2);
	if (!parse->text)
		return ;
	parse->text[0] = 0;
	parse->text[1] = 0;
	parse->rx = 0;
	parse->ry = 0;
	parse->error = 0;
	parse->no_text = 0;
	parse->so_text = 0;
	parse->we_text = 0;
	parse->ea_text = 0;
	parse->sprite_text = 0;
	parse->rfloor = 0;
	parse->gfloor = 0;
	parse->bfloor = 0;
	parse->rceil = 0;
	parse->gceil = 0;
	parse->bceil = 0;
	parse->map_size = 0;
    parse->player_or = 0;
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
