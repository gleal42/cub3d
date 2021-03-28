/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 19:42:43 by gleal             #+#    #+#             */
/*   Updated: 2021/03/28 22:04:45 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonuscub.h"

void	cleanclose(t_adata *a)
{
	free(a->parse.no_text);
	free(a->parse.so_text);
	free(a->parse.we_text);
	free(a->parse.ea_text);
	free(a->parse.sprite_text);
	clean_sprites(a, &a->sps);
	ft_freetext(a->parse.mapstr);
	mlx_destroy_window(a->win.mlx, a->win.win);
	exit(EXIT_SUCCESS);
}

int		clicked_cross(int keycode, t_adata *a)
{
	(void)keycode;
	(void)a;
	exit(EXIT_SUCCESS);
	return (0);
}

int		butt_released(int keycode, t_adata *a)
{
	if (keycode == W_KEY)
		a->joe.walkdir = 0;
	else if (keycode == S_KEY)
		a->joe.walkdir = 0;
	else if (keycode == A_KEY)
		a->joe.walkdir = 0;
	else if (keycode == D_KEY)
		a->joe.walkdir = 0;
	else if (keycode == RIGHT_ARROW)
		a->joe.turndir = 0;
	else if (keycode == LEFT_ARROW)
		a->joe.turndir = 0;
	return (0);
}

int		butt_pressed(int keycode, t_adata *a)
{
	if (keycode == ESC_KEY)
		cleanclose(a);
	if (keycode == W_KEY)
		a->joe.walkdir = 'w';
	else if (keycode == S_KEY)
		a->joe.walkdir = 's';
	else if (keycode == A_KEY)
		a->joe.walkdir = 'a';
	else if (keycode == D_KEY)
		a->joe.walkdir = 'd';
	else if (keycode == RIGHT_ARROW)
		a->joe.turndir = 1;
	else if (keycode == LEFT_ARROW)
		a->joe.turndir = -1;
	return (0);
}
