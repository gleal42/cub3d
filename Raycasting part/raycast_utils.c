/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 13:21:39 by gleal             #+#    #+#             */
/*   Updated: 2021/03/15 16:46:59 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

double	spawnrotation(char c)
{
	if (c == 'E')
		return (0);
	else if (c == 'S')
		return (M_PI_2);
	else if (c == 'W')
		return (M_PI);
	else
		return (3 * M_PI_2);
}

void	ft_playerinfo(t_map2d *map, t_player *joe, char **strs)
{
	int		i;
	int		j;

	i = 0;
	while (strs[i])
	{
		j = 0;
		while (strs[i][j])
		{
			if (ft_strchr("NSEW", strs[(int)i][(int)j]))
			{
				joe->x = (double)((j + 0.5) * map->tile_size);
				joe->y = (double)((i + 0.5) * map->tile_size);
				joe->rotangle = spawnrotation(strs[i][j]);
			}
			j++;
		}
		i++;
	}
}

int		ft_max_strlen(char **strs)
{
	int		i;
	int		j;
	int		max_len;

	i = 0;
	j = 0;
	max_len = 0;
	while (strs[i])
	{
		j = 0;
		while (strs[i][j])
			j++;
		if (j > max_len)
			max_len = j;
		i++;
	}
	return (max_len);
}

int		ft_count_lines(char **strs)
{
	int i;

	i = 0;
	while (strs[i])
		i++;
	return (i);
}

char	**ft_test_map(void)
{
	char	**official;
	int		i;
	char 	*temp[] = {
"        1111111111111111111111111",
"        1000000000110000000000001",
"        1011000001110000002000001",
"        1001000000000000000000001",
"111111111011000001110000000000001",
"100000000011000001110111110111111",
"11110111111111011100000010001",
"11110111111111011101010010001",
"11000000110101011100000010001",
"10002000000000001100000010001",
"10000000000000001101010010001",
"11000001110101011111011110S0111",
"11110111 1110101 101111010001",
"11111111 1111111 111111111111",
0
	};

	i = 0;
	ft_count_lines(temp);
	official = malloc(sizeof(char*) * (ft_count_lines(temp) + 1));
	while (temp[i])
	{
		official[i] = ft_strdup(temp[i]);
		i++;
	}
	official[i] = 0;
	return (official);
}
