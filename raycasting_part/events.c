/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 19:42:43 by gleal             #+#    #+#             */
/*   Updated: 2021/03/18 18:03:09 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

int		butt_released(int keycode, t_adata *a)
{
	if (keycode == UP_ARROW)
		a->joe.walkdir = 0;
	if (keycode == DOWN_ARROW)
		a->joe.walkdir = 0;
	if (keycode == RIGHT_ARROW)
		a->joe.turndir = 0;
	if (keycode == LEFT_ARROW)
		a->joe.turndir = 0;
	return (0);
}

int		butt_pressed(int keycode, t_adata *a)
{
	if (keycode == UP_ARROW)
		a->joe.walkdir = 1;
	if (keycode == DOWN_ARROW)
		a->joe.walkdir = -1;
	if (keycode == RIGHT_ARROW)
		a->joe.turndir = 1;
	if (keycode == LEFT_ARROW)
		a->joe.turndir = -1;
	return (0);
}