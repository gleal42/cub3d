/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 19:42:43 by gleal             #+#    #+#             */
/*   Updated: 2021/03/09 19:55:28 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

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
		printf("%f\n", a->joe.walkdir);
	return (1);
}

void	events(t_adata *a)
{
	mlx_hook(a->win.win, 2, 1L<<0, butt_pressed, &a);
	mlx_hook(a->win.win, 3, 1L<<1, butt_released, &a);
}
