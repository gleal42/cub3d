/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:20:19 by gleal             #+#    #+#             */
/*   Updated: 2021/03/09 22:18:08 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	draw_player(double p_w, double p_h, t_adata *a)
{
	if (sqrt(pow(a->joe.x - p_w, 2) + pow(a->joe.y - p_h, 2)) <= a->joe.radius)
		a->img_m.addr[(int)(p_h * a->map.map_w + p_w)] = 0xb87cb3;
	
}

void	draw_map(double  p_w, double  p_h, t_adata *a)
{
	int	cur_x;
	int cur_y;

	cur_x = (int)p_w/a->map.tile_size;
	cur_y = (int)p_h/a->map.tile_size;

	if (cur_x >= ft_strlen(a->map.maptxt[cur_y]))
		a->img_m.addr[(int)(p_h * a->map.map_w + p_w)] = 0xD6D6D6;
	else if (a->map.maptxt[cur_y][cur_x] == '1')
		a->img_m.addr[(int)(p_h * a->map.map_w + p_w)] = 0x85b569;
	else if (ft_strchr("02NSWE", a->map.maptxt[cur_y][cur_x]))
		a->img_m.addr[(int)(p_h * a->map.map_w + p_w)] = 0xebdbb7;
	else
		a->img_m.addr[(int)(p_h * a->map.map_w + p_w)] = 0xD6D6D6;
}

void	render_map(t_adata *a, void (*draw)(double, double, t_adata *a))
{
	int	pixel_w;
	int	pixel_h;

	pixel_h = 0;
	while (pixel_h < a->map.map_h)
	{
		pixel_w = 0;
		while (pixel_w < a->map.map_w)
		{
			draw(pixel_w, pixel_h, a);
			pixel_w++;
		}
		pixel_h++;
	}
		mlx_put_image_to_window(a->win.mlx, a->win.win, a->img_m.ptr, 0, 0);
}

int     main(void)
{
	t_adata a;

	ft_init_win(&a);
	ft_init_map(&a);
	ft_init_img(&a);
	ft_init_player(&a);	
	render_map(&a, &draw_map);
	render_map(&a, &draw_player);
	mlx_destroy_image (a.win.mlx, a.img_m.ptr);
	events(&a);
	//mlx_loop_hook(mlx, render_next_frame, &a);
	mlx_loop(a.win.mlx);
	return (0);
}
