/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 14:04:29 by gleal             #+#    #+#             */
/*   Updated: 2021/03/25 18:59:25 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
