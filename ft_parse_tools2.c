/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_tools2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 18:58:48 by gleal             #+#    #+#             */
/*   Updated: 2021/03/19 21:28:52 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_valid_map(char **strs, t_parse *parse)
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
			if (!playeringame(parse))
				return (0);
		}
		else
		{
			if (!checkfirstwall(strs[i]))
				return (0);
			if (!checkmapclosed(&strs[i]))
				return (0);
			if (!checkmultiplayer(strs[i], parse))
				return (0);
		}
		i++;
	}
	parse->map_size = i;
	if (!ft_copy_map(strs, parse))
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
	while (ft_isspace(str[i])  || str[i] == ',')
		i++;
	if (!isdigit(str[i]))
		return (0);
	parse->bceil = ft_atoi(&str[i]);
	if (parse->rceil < 0 || parse-> rceil > 255)
		return (0);
	if (parse->gceil < 0 || parse-> gceil > 255)
		return (0);
	if (parse->bceil < 0 || parse-> bceil > 255)
		return (0);
	return (1);
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
	while (ft_isspace(str[i])  || str[i] == ',')
		i++;
	if (!isdigit(str[i]))
		return (0);
	parse->bfloor = ft_atoi(&str[i]);
	if (parse->rfloor < 0 || parse-> rfloor > 255)
		return (0);
	if (parse->gfloor < 0 || parse-> gfloor > 255)
		return (0);
	if (parse->bfloor < 0 || parse-> bfloor > 255)
		return (0);
	return (1);
}
