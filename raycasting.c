/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:20:19 by gleal             #+#    #+#             */
/*   Updated: 2021/03/08 16:52:28 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "raycasting.h"

void	draw_map(int  p_w, int  p_h, t_adata *a)
{
	int	cur_x;
	int cur_y;

	cur_x = p_w/a->map.tile_size;
	cur_y = p_h/a->map.tile_size;

	if (cur_x >= ft_strlen(a->map.maptxt[cur_y]))
		a->map.addr[p_h * a->map.map_w + p_w] = 0xD6D6D6;
	else if (a->map.maptxt[cur_y][cur_x] == '1')
		a->map.addr[p_h * a->map.map_w + p_w] = 0x6F9C53;
	else if (ft_strchr("02NSWE", a->map.maptxt[cur_y][cur_x]))
		a->map.addr[p_h * a->map.map_w + p_w] = 0xECD6A8;
	else
		a->map.addr[p_h * a->map.map_w + p_w] = 0xD6D6D6;
}

void	render_map(t_adata *a)
{
	int	pixel_w;
	int	pixel_h;

	pixel_h = 0;
	while (pixel_h < a->map.map_h)
	{
		pixel_w = 0;
		while (pixel_w < a->map.map_w)
		{
			draw_map(pixel_w, pixel_h, a);
			 pixel_w++;
		}
		pixel_h++;
	}
		mlx_put_image_to_window(a->win.mlx, a->win.win, a->map.map2d, 0, 0);
	    mlx_loop(a->win.mlx);
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
	map.addr = (int *)mlx_get_data_addr(map.map2d, &map.pixel_bits, &map.line_bytes, &map.endian);
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

int     main(void)
{
	t_adata a;

	ft_init_win(&a);
	ft_init_map(&a);
	render_map(&a);
	//ft_init_player(&a);
	return (0);
}
