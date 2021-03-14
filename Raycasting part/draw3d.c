/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 20:16:24 by gleal             #+#    #+#             */
/*   Updated: 2021/03/14 22:16:49 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

int		line3d(t_line line_3d, t_adata *a)
{
	double remain_pixels;
	double pixelx;
	double pixely;
	pixelx = line_3d.start_x;
	pixely = line_3d.start_y;
	remain_pixels = line_3d.pixels;
	while (remain_pixels >= 0)
	{
		a->img_3d.addr[(int)pixely * (int)a->win.win_w + (int)pixelx] = line_3d.color;
		pixelx += line_3d.deltax;
		pixely += line_3d.deltay;
		--remain_pixels;
	}
	return (0);
}

int		ft_prepare_3d_line(double ray_angle, t_ray *ray, t_adata *a, int col_id)
{
	int		line_height;

	line_height = (int)(a->win.win_h/(a->map.map_h/ray->distance));
	a->line_3d.start_x = col_id;
	a->line_3d.start_y = (a->win.win_h/2) - (line_height/2);
	if(a->line_3d.start_y < 0)
		a->line_3d.start_y= 0;
	a->line_3d.end_x = col_id;
	a->line_3d.end_y = (a->win.win_h/2) + (line_height/2);
	if(a->line_3d.end_y >= a->win.win_h)
		a->line_3d.end_y = a->win.win_h - 1;
	a->line_3d.deltax = a->line.end_x - a->line.start_x;
	a->line_3d.deltay = a->line.end_y - a->line.start_y;
	a->line_3d.pixels = sqrt(pow(a->line.deltax, 2) + pow(a->line.deltay, 2));
	a->line_3d.deltax /= a->line.pixels;
	a->line_3d.deltay /= a->line.pixels;
	a->line_3d.color = 0x77b3cf;

	printf("ray->distance%f\n", ray->distance);
	return (0);
}

int		draw3d(double ray_angle, t_ray *ray, t_adata *a, int col_id)
{
	ft_prepare_3d_line(ray_angle, ray, a, col_id);
	line3d(a->line_3d, a);
	return (0);
}
