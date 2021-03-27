/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 14:04:29 by gleal             #+#    #+#             */
/*   Updated: 2021/03/27 19:34:18 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
