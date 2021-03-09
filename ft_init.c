/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 17:40:35 by gleal             #+#    #+#             */
/*   Updated: 2021/03/09 12:14:02 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "raycasting.h"

void	ft_init_player(t_adata *a)
{
	t_player	joe;

	ft_playerinfo(&a->map, &joe, a->map.maptxt);
	joe.radius = a->map.tile_size / 4;
	joe.turndir = 0;
	joe.walkdir = 0;
	joe.movespeed = 3.0;
	joe.rotatespeed = 3 * (M_PI / 180);
	joe.joe = mlx_new_image(a->win.mlx, a->map.map_w, a->map.map_h);
	joe.addr = (int *)mlx_get_data_addr(joe.joe,
	&joe.pixel_bits, &joe.line_bytes, &joe.endian);
	joe.line_bytes /= 4;
	a->joe = joe;
}

void	ft_init_map(t_adata *a)
{
	t_map2d	map;

	map.maptxt = ft_test_map();
	map.map_rows = ft_count_lines(map.maptxt);
	map.map_cols = ft_max_strlen(map.maptxt);
	map.tile_size = 32;
	map.map_h = map.map_rows * map.tile_size;
	map.map_w = map.map_cols * map.tile_size;
	map.map2d = mlx_new_image(a->win.mlx, map.map_w, map.map_h);
	map.addr = (int *)mlx_get_data_addr(map.map2d,
	&map.pixel_bits, &map.line_bytes, &map.endian);
	map.line_bytes /= 4;
	a->map = map;
}

void	ft_init_win(t_adata *a)
{
	t_win		win;

	win.mlx = mlx_init();
	win.win_w = 1920;
	win.win_h = 1080;
	win.win = mlx_new_window(win.mlx, win.win_w, win.win_h, "Wolfenstein3D");
	a->win = win;
}
