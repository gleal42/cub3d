/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:20:19 by gleal             #+#    #+#             */
/*   Updated: 2021/03/08 22:04:49 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "raycasting.h"

void	draw_player(double p_w, double p_h, t_adata *a)
{
	if (sqrt(pow(a->joe.x - p_w, 2) + pow(a->joe.y - p_h, 2)) <= a->joe.radius)
		a->map.addr[(int)(p_h * a->map.map_w + p_w)] = 0xCD406F;
}

void	render_player(t_adata *a)
{
	double	pixel_w;
	double	pixel_h;

	pixel_h = 0;
	while (pixel_h < a->map.map_h)
	{
		pixel_w = 0;
		while (pixel_w < a->map.map_w)
		{
			draw_player(pixel_w, pixel_h, a);
			 pixel_w++;
		}
		pixel_h++;
	}
		mlx_put_image_to_window(a->win.mlx, a->win.win, a->map.map2d, 0, 0);

}

void	draw_map(int  p_w, int  p_h, t_adata *a)
{
	int	cur_x;
	int cur_y;

	cur_x = p_w/a->map.tile_size;
	cur_y = p_h/a->map.tile_size;

	if (cur_x >= ft_strlen(a->map.maptxt[cur_y]))
		a->map.addr[(int)(p_h * a->map.map_w + p_w)] = 0xD6D6D6;
	else if (a->map.maptxt[cur_y][cur_x] == '1')
		a->map.addr[(int)(p_h * a->map.map_w + p_w)] = 0x6F9C53;
	else if (ft_strchr("02NSWE", a->map.maptxt[cur_y][cur_x]))
		a->map.addr[(int)(p_h * a->map.map_w + p_w)] = 0xFEE4C6;
	else
		a->map.addr[(int)(p_h * a->map.map_w + p_w)] = 0xD6D6D6;
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
}

int     main(void)
{
	t_adata a;

	ft_init_win(&a);
	ft_init_map(&a);
	render_map(&a);
	ft_init_player(&a);
	render_player(&a);
	mlx_loop(a.win.mlx);
	return (0);
}
