/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:20:19 by gleal             #+#    #+#             */
/*   Updated: 2021/03/19 20:17:32 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	ft_init_all(t_adata *a)
{
	ftinit_map(a);
	ftinit_player(a);
	ftinit_texts(a);
	ftinit_rays(a);
	ftinit_sprites(a);
}

int		render_next_frame(t_adata *a)
{
	ftinit_img_3d(a);
	ftinit_img_m(a);
	ft_update_player(a);
	update_sprites(a);
	draw_map(a);
	draw_minicircle(a);
	ft_initline(a);
	line(a->line, a);
	draw3d(a);
	mlx_put_image_to_window(a->win.mlx, a->win.win, a->img_3d.ptr, 0, 0);
	mlx_put_image_to_window(a->win.mlx, a->win.win, a->img_m.ptr, 0, 0);
	destroyimg(a, &a->img_m);
	destroyimg(a, &a->img_3d);
	return (0);
}

int		start_game(t_adata *a)
{
	a->win.mlx = mlx_init();
	a->win.win_w = 1920;
	a->win.win_h = 1080;
	a->win.win = mlx_new_window(a->win.mlx, a->win.win_w,
	a->win.win_h, "Wolfenstein3D");
	ft_init_all(a);
	mlx_do_key_autorepeatoff(a->win.mlx);
	mlx_hook(a->win.win, 2, 1L << 0, &butt_pressed, a);
	mlx_hook(a->win.win, 3, 1L << 1, &butt_released, a);
	mlx_loop_hook(a->win.mlx, &render_next_frame, a);
	mlx_loop(a->win.mlx);
	return (1);
}