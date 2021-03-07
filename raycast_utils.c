/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 13:21:39 by gleal             #+#    #+#             */
/*   Updated: 2021/03/07 20:10:58 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "raycasting.h"

int		ft_count_lines(char **strs)
{
	int i;

	i = 0;
	while (strs[i])
		i++;
	return (i);
}


void	screenstart(t_datat *data)
{
	data->window_width = 1920;
	data->window_height = 1080;
	data->mapinfo->map = ft_test_map();
	data->mapinfo->map_num_rows = ft_count_lines(data->mapinfo->map);
	data->mapinfo->tile_size = (data->window_height/2) / data->mapinfo->map_num_rows;
	
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
"100000000011000001110111111111111",
"11110111111111011100000010001",
"11110111111111011101010010001",
"11000000110101011100000010001",
"10002000000000001100000010001",
"10000000000000001101010010001",
"11000001110101011111011110N0111",
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

void	ft_allocinfo(t_datat **data)
{
	*data = (t_datat*)malloc(sizeof(t_datat));
	(*data)->mapinfo = (t_testmap*)malloc(sizeof(t_testmap));
	(*data)->player = (t_player*)malloc(sizeof(t_player));
}

