/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 19:42:43 by gleal             #+#    #+#             */
/*   Updated: 2021/03/10 22:03:07 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

int		render_next_frame(t_adata *a)
{
	ft_init_img(a);
	update(a);
	render_mini(a, &drawbycomp);
	ft_init_dirline(a);
	draw_dirline(a);
	mlx_put_image_to_window(a->win.mlx, a->win.win, a->img_m.ptr, 0, 0);
	mlx_destroy_image (a->win.mlx, a->img_m.ptr);
	return (0);
}

int		butt_released(int keycode, t_adata *a)
{
	if (keycode == UP_ARROW)
		a->joe.walkdir = 0;
	else if (keycode == DOWN_ARROW)
		a->joe.walkdir = 0;
	else if (keycode == RIGHT_ARROW)
		a->joe.turndir = 0;
	else if (keycode == LEFT_ARROW)
		a->joe.turndir = 0;
	//printf("%d\n", a->joe.turndir);
	//printf("%d\n", a->joe.walkdir);
	return (1);
}
int		butt_pressed(int keycode, t_adata *a)
{
	if (keycode == UP_ARROW)
		a->joe.walkdir = 1;
	else if (keycode == DOWN_ARROW)
		a->joe.walkdir = -1;
	else if (keycode == RIGHT_ARROW)
		a->joe.turndir = 1;
	else if (keycode == LEFT_ARROW)
		a->joe.turndir = -1;
		printf("%d\n", a->joe.turndir);
		printf("%d\n", a->joe.walkdir);
	return (1);
}

void	events(t_adata *a)
{
	//mlx_do_key_autorepeatoff(a->win.mlx);
	mlx_hook(a->win.win, 2, 1L<<0, butt_pressed, &a);
	mlx_hook(a->win.win, 3, 1L<<1, butt_released, &a);
}
