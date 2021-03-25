/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_tools2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 18:58:48 by gleal             #+#    #+#             */
/*   Updated: 2021/03/25 17:54:19 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		is_map(char *str)
{
	if (*str == '\0')
		return (0);
	while (*str)
	{
		if (!ft_isspace(*str) && !ft_strchr(MAP_CHARS, *str))
			return (0);
		str++;
	}
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
