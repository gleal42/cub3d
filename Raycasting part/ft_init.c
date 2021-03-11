/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 17:40:35 by gleal             #+#    #+#             */
/*   Updated: 2021/03/11 21:14:26 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	ft_init_player(t_adata *a)
{
	ft_playerinfo(&a->map, &a->joe, a->map.maptxt);
	a->joe.radius = a->map.tile_size / 6;
	a->joe.turndir = 0;
	a->joe.walkdir = 0;
	a->joe.movespeed = 5.0;
	a->joe.rotatespeed = 7 * (M_PI / 180);
}

void	ft_init_img(t_adata *a)
{
	a->img_m.ptr = mlx_new_image(a->win.mlx, a->map.map_w, a->map.map_h);
	a->img_m.addr = (int *)mlx_get_data_addr(a->img_m.ptr,
	&a->img_m.pixel_bits, &a->img_m.line_bytes, &a->img_m.endian);
}

void	ft_init_map(t_adata *a)
{
	a->map.maptxt = ft_test_map();
	a->map.map_rows = ft_count_lines(a->map.maptxt);
	a->map.map_cols = ft_max_strlen(a->map.maptxt);
	a->map.tile_size = 32;
	a->map.map_h = a->map.map_rows * a->map.tile_size;
	a->map.map_w = a->map.map_cols * a->map.tile_size;
}

void	ft_init_win(t_adata *a)
{
	t_win		win;

	a->win.mlx = mlx_init();
	a->win.win_w = 1920;
	a->win.win_h = 1080;
	a->win.win = mlx_new_window(a->win.mlx, a->win.win_w, a->win.win_h, "Wolfenstein3D");
}

void	ft_init_all(t_adata *a)
{
	ft_init_win(a);
	ft_init_map(a);
	ft_init_player(a);
}
