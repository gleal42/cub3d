/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_cub_utils2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 19:24:46 by gleal             #+#    #+#             */
/*   Updated: 2021/03/28 15:47:14 by gleal            ###   ########.fr       */
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
