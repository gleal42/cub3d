/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_tools2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 18:58:48 by gleal             #+#    #+#             */
/*   Updated: 2021/03/27 19:32:57 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_rgb_ceil_check(t_parse *parse)
{
	if (parse->rceil < 0 || parse->rceil > 255)
		return (0);
	if (parse->gceil < 0 || parse->gceil > 255)
		return (0);
	if (parse->bceil < 0 || parse->bceil > 255)
		return (0);
	return (1);
}

int		ft_rgb_floor_check(t_parse *parse)
{
	if (parse->rfloor < 0 || parse->rfloor > 255)
		return (0);
	if (parse->gfloor < 0 || parse->gfloor > 255)
		return (0);
	if (parse->bfloor < 0 || parse->bfloor > 255)
		return (0);
	return (1);
}

int		ft_parseceilcolor(char *str, t_parse *parse)
{
	int		i;

	i = 1;
	while (ft_isspace(str[i]) || str[i] == ',')
		i++;
	if (!isdigit(str[i]))
		return (0);
	parse->rceil = ft_atoi(&str[i]);
	while (ft_isdigit(str[i]))
		i++;
	while (ft_isspace(str[i]) || str[i] == ',')
		i++;
	if (!isdigit(str[i]))
		return (0);
	parse->gceil = ft_atoi(&str[i]);
	while (ft_isdigit(str[i]))
		i++;
	while (ft_isspace(str[i]) || str[i] == ',')
		i++;
	if (!isdigit(str[i]))
		return (0);
	parse->bceil = ft_atoi(&str[i]);
	return (ft_rgb_ceil_check(parse));
}

int		ft_parsefloorcolor(char *str, t_parse *parse)
{
	int		i;

	i = 1;
	while (ft_isspace(str[i]) || str[i] == ',')
		i++;
	if (!isdigit(str[i]))
		return (0);
	parse->rfloor = ft_atoi(&str[i]);
	while (ft_isdigit(str[i]))
		i++;
	while (ft_isspace(str[i]) || str[i] == ',')
		i++;
	if (!isdigit(str[i]))
		return (0);
	parse->gfloor = ft_atoi(&str[i]);
	while (ft_isdigit(str[i]))
		i++;
	while (ft_isspace(str[i]) || str[i] == ',')
		i++;
	if (!isdigit(str[i]))
		return (0);
	parse->bfloor = ft_atoi(&str[i]);
	return (ft_rgb_floor_check(parse));
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
