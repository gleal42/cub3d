/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 17:40:35 by gleal             #+#    #+#             */
/*   Updated: 2021/03/10 20:54:41 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	ft_init_player(t_adata *a)
{
	t_player	joe;

	ft_playerinfo(&a->map, &joe, a->map.maptxt);
	joe.radius = a->map.tile_size / 6;
	joe.turndir = 0;
	joe.walkdir = 0;
	joe.movespeed = 3.0;
	joe.rotatespeed = 3 * (M_PI / 180);
	a->joe = joe;
}

void	ft_init_img(t_adata *a)
{
	t_img	img_m;

	img_m.ptr = mlx_new_image(a->win.mlx, a->map.map_w, a->map.map_h);
	img_m.addr = (int *)mlx_get_data_addr(img_m.ptr,
	&img_m.pixel_bits, &img_m.line_bytes, &img_m.endian);
	img_m.line_bytes /= 4;
	a->img_m = img_m;
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

void	ft_init_all(t_adata *a)
{
	ft_init_win(a);
	ft_init_map(a);
	ft_init_player(a);
}
