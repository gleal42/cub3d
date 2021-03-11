/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:20:19 by gleal             #+#    #+#             */
/*   Updated: 2021/03/11 21:00:47 by gleal            ###   ########.fr       */
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

int draw_line(void *mlx, void *win, int beginx, int beginy, int endx, int endy, t_adata *a)
{
	double deltax = endx - beginx;
	double deltay = endy - beginy;
	int pixels = sqrt(pow(deltax, 2) + pow(deltay, 2));
	deltax /= pixels;
	deltay /= pixels;
	double pixelx = beginx;
	double pixely = beginy;
	while (pixels)
	{
		a->img_m.addr[(int)pixely * a->map.map_w + (int)pixelx] =0xb87cb3;
		pixelx += deltax;
		pixely += deltay;
		--pixels;
	}
	return (0);
}

int 	ft_initline(t_adata *a)
{
	a->line.end_x = a->joe.x + (cos(a->joe.rotangle) * a->map.tile_size );
	a->line.end_y = a->joe.y + (sin(a->joe.rotangle) * a->map.tile_size );
	return (0);
}

int		render_next_frame(t_adata *a)
{
	ft_init_img(a);
	ft_update(a);
	draw_map(a);
	draw_minicircle(a);
	ft_initline(a);
	draw_line(a->win.mlx, a->win.win, a->line.end_x, a->line.end_y, a->joe.x, a->joe.y, a);
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
