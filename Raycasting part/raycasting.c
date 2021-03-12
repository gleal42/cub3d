/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:20:19 by gleal             #+#    #+#             */
/*   Updated: 2021/03/12 18:26:36 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

int 	destroy_img(t_adata *a)
{
	mlx_destroy_image (a->win.mlx, a->img_m.ptr);
	a->img_m.ptr = 0;
	a->img_m.addr = 0;
	return (0);
}

int		line(t_line line, t_adata *a)
{
	double remain_pixels;
	double pixelx;
	double pixely;
	pixelx = line.start_x;
	pixely = line.start_y;
	remain_pixels = line.pixels;
	while (remain_pixels >= 0)
	{
		a->img_m.addr[(int)pixely * a->map.map_w + (int)pixelx] = line.color;
		pixelx += line.deltax;
		pixely += line.deltay;
		--remain_pixels;
	}
	return (0);
}

int 	ft_initline(t_adata *a)
{
	a->line.start_x = a->joe.x;
	a->line.start_y = a->joe.y;
	a->line.end_x = a->joe.x + (cos(a->joe.rotangle) * a->map.tile_size );
	a->line.end_y = a->joe.y + (sin(a->joe.rotangle) * a->map.tile_size );
	a->line.deltax = a->line.end_x - a->line.start_x;
	a->line.deltay = a->line.end_y - a->line.start_y;
	a->line.pixels = sqrt(pow(a->line.deltax, 2) + pow(a->line.deltay, 2));
	a->line.deltax /= a->line.pixels;
	a->line.deltay /= a->line.pixels;
	a->line.color = 0xb87cb3;
	return (0);
}

int		render_next_frame(t_adata *a)
{
	ft_init_img(a);
	ft_update(a);
	draw_map(a);
	draw_minicircle(a);
	ft_initline(a);
	line(a->line, a);
	cast_rays(a);
	mlx_put_image_to_window(a->win.mlx, a->win.win, a->img_m.ptr, 0, 0);
	destroy_img(a);
	return (0);
}

int     main(void)
{
	t_adata a;

	ft_init_all(&a);
	mlx_do_key_autorepeatoff(a.win.mlx);
	mlx_hook(a.win.win, 2, 1L<<0, &butt_pressed, &a);
	mlx_hook(a.win.win, 3, 1L<<1, &butt_released, &a);
	mlx_loop_hook(a.win.mlx, &render_next_frame, &a);
	mlx_loop(a.win.mlx);
	return (1);
}
