/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 12:58:40 by gleal             #+#    #+#             */
/*   Updated: 2021/03/10 21:41:43 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	draw_dirline(t_adata *a)
{
	ft_init_dirline(a);
	a->dir_l.pixelx = a->dir_l.start_x;
	a->dir_l.pixely = a->dir_l.start_y;

	while (a->dir_l.pixels)
	{
		a->img_m.addr[(int)(a->dir_l.pixely * a->map.map_w + a->dir_l.pixelx)] = 0x7cb3b8;
		a->dir_l.pixelx += a->dir_l.deltax;
		a->dir_l.pixely += a->dir_l.deltay;
		a->dir_l.pixels--;
	}
	}

void	draw_minicircle(double p_w, double p_h, t_adata *a)
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

void	drawbycomp(double  p_w, double  p_h, t_adata *a)
{
	draw_map(p_w, p_h, a);
	draw_minicircle(p_w, p_h, a);
}
