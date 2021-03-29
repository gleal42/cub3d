/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 18:05:01 by gleal             #+#    #+#             */
/*   Updated: 2021/03/29 19:17:25 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_copy_map(char **map_start, t_parse *parse)
{
	char	**temp;
	int		i;

	i = 0;
	temp = malloc(sizeof(char*) * (parse->nbr_str + 2));
	if (!temp)
	{
		ft_freetext(parse->text);
		return (0);
	}
	while (is_map(map_start[i]))
	{
		temp[i] = ft_strdup(map_start[i]);
		if (!temp[i])
		{
			ft_freetext(parse->text);
			ft_free_to_str(&temp, i - 1);
			return (0);
		}
		i++;
	}
	temp[i] = NULL;
	parse->mapstr = temp;
	return (1);
}

int		checkmultiplayer(char *str, t_parse *parse)
{
	while (*str)
	{
		if (ft_strchr(PLAYER, *str))
		{
			if (!parse->player_or)
				parse->player_or = *str;
			else
				return (0);
		}
		str++;
	}
	return (1);
}
