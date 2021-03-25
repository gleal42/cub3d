/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_cub_utils2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 19:24:46 by gleal             #+#    #+#             */
/*   Updated: 2021/03/25 20:14:51 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_screensize(char *str, t_parse *parse)
{
	int		i;

	i = 1;
	while (ft_isspace(str[i]))
		i++;
	parse->rx = ft_atoi(&str[i]);
	while (ft_isdigit(str[i]))
		i++;
	while (ft_isspace(str[i]))
		i++;
	parse->ry = ft_atoi(&str[i]);
	if (parse->rx <= 0 || parse->ry <= 0 ||
	parse->rx > MAX_X_SIZE || parse->ry > MAX_Y_SIZE)
		return (0);
	return (1);
}

int		check_resolution(char **text, t_parse *parse, int *i, int *count)
{
	if (text[(*i)][0] == 'R')
	{
		if (parse->rx || parse->ry)
			return (ft_error(MULTIRES));
		if (!ft_screensize(text[(*i)], parse))
			return (ft_error(BADSCREEN));
		(*count)++;
		(*i)++;
	}
	return (1);
}

int		check_rgbs(char **text, t_parse *parse, int *i, int *count)
{
	if (text[(*i)][0] == 'F')
	{
		if (parse->rfloor || parse->gfloor || parse->bfloor)
			return (ft_error(MULTIFLOOR));
		if (!ft_parsefloorcolor(text[(*i)], parse))
			return (ft_error(BADFLOOR));
		(*count)++;
		(*i)++;
	}
	if (text[(*i)][0] == 'C')
	{
		if (parse->rceil || parse->gceil || parse->bceil)
			return (ft_error(MULTICEIL));
		if (!ft_parseceilcolor(text[(*i)], parse))
			return (ft_error(BADCEIL));
		(*count)++;
		(*i)++;
	}
	return (1);
}

int		check_valid_chars(char **text, int *i)
{
	if (text[(*i)][0] == 'N' && text[(*i)][1] == 'O')
		return (1);
	if (text[(*i)][0] == 'S' && text[(*i)][1] == 'O')
		return (1);
	if (text[(*i)][0] == 'W' && text[(*i)][1] == 'E')
		return (1);
	if (text[(*i)][0] == 'E' && text[(*i)][1] == 'A')
		return (1);
	if (text[(*i)][0] == 'S' && text[(*i)][1] != 'O')
		return (1);
	if (text[(*i)][0] == 'F')
		return (1);
	if (text[(*i)][0] == 'C')
		return (1);
	if (text[(*i)][0] == '\0')
		return (1);
	if (text[(*i)] == NULL)
		return (1);
	return (0);
}
