/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_textures.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 18:06:19 by gleal             #+#    #+#             */
/*   Updated: 2021/04/01 00:09:43 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
/* Using the elements initials to identify them. We need to use both because sprites and south both start with S */
int		check_walltextures_horiz(char **text, t_parse *parse,
		int *i, int *count)
{
	if (text[(*i)][0] == 'N' && text[(*i)][1] == 'O')
	{
		if (parse->no_text)
			return (ft_error(MULTINO));
		if (!ft_parsenorthtext(text[(*i)], parse))
			return (ft_error(BADNO));
		(*count)++;
		(*i)++;
	}
	if (text[(*i)][0] == 'S' && text[(*i)][1] == 'O')
	{
		if (parse->so_text)
			return (ft_error(MULTISO));
		if (!ft_parsesouthtext(text[(*i)], parse))
			return (ft_error(BADSO));
		(*count)++;
		(*i)++;
	}
	return (1);
}

int		check_walltextures_vert(char **text, t_parse *parse, int *i, int *count)
{
	if (text[(*i)][0] == 'W' && text[(*i)][1] == 'E')
	{
		if (parse->we_text)
			return (ft_error(MULTIWE));
		if (!ft_parsewesttext(text[(*i)], parse))
			return (ft_error(BADWE));
		(*count)++;
		(*i)++;
	}
	if (text[(*i)][0] == 'E' && text[(*i)][1] == 'A')
	{
		if (parse->ea_text)
			return (ft_error(MULTIEA));
		if (!ft_parseeasttext(text[(*i)], parse))
			return (ft_error(BADEA));
		(*count)++;
		(*i)++;
	}
	return (1);
}

int		check_spritetextures(char **text, t_parse *parse, int *i, int *count)
{
	if (text[(*i)][0] == 'S' && text[(*i)][1] != 'O')
	{
		if (parse->sprite_text)
			return (ft_error(MULTISPRITE));
		if (!ft_parsespritetext(text[(*i)], parse))
			return (ft_error(BADSPRITE));
		(*count)++;
		(*i)++;
	}
	return (1);
}

int		check_textures(char **text, t_parse *parse, int *i, int *count)
{
	if (!check_walltextures_horiz(text, parse, i, count))
		return (0);
	if (!check_walltextures_vert(text, parse, i, count))
		return (0);
	if (!check_spritetextures(text, parse, i, count))
		return (0);
	return (1);
}
