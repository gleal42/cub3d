/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 18:53:52 by gleal             #+#    #+#             */
/*   Updated: 2021/03/29 17:02:46 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonuscub.h"

int		linesprite(t_item *item,
		t_adata *a, int col_id)
{
	double remain_pixels;
	double pixelx;
	double pixely;
	double texx;
	double texy;

	pixelx = a->line_sp.start_x;
	pixely = a->line_sp.start_y;
	texy = 0;
	texx = bitmap_offset_sp(item, col_id);
	remain_pixels = a->line_sp.pixels;
	while (remain_pixels > 0)
	{
		if (item->imgsp.addr[(int)texy * (int)item->imgsp.width + (int)texx])
			a->img_3d.addr[((int)pixely * (int)a->win.win_w + (int)pixelx)] =
			item->imgsp.addr[(int)texy * (int)item->imgsp.width + (int)texx];
		pixelx += a->line_sp.deltax;
		pixely += a->line_sp.deltay;
		texy = ((pixely - a->line_sp.start_y) *
		item->imgsp.width) / a->line_sp.pixels;
		--remain_pixels;
	}
	return (0);
}

int		line3d(t_ray *ray, t_adata *a)
{
	double		remain_pixels;
	double		pixelx;
	double		pixely;
	int			texx;
	int			texy;

	pixelx = a->line_3d.start_x;
	pixely = a->line_3d.start_y;
	texy = 0;
	texx = bitmap_offset(ray, a);
	remain_pixels = a->line_3d.pixels;
	while (remain_pixels > 0)
	{
		a->img_3d.addr[((int)pixely * (int)a->win.win_w + (int)pixelx)] =
		a->notext.imgt.addr[(int)texy *
		(int)a->notext.imgt.width + (int)texx];
		pixelx += a->line_3d.deltax;
		pixely += a->line_3d.deltay;
		texy = ((pixely - a->line_3d.start_y) *
		a->notext.imgt.width) / a->line_3d.pixels;
		--remain_pixels;
	}
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
	while (remain_pixels > 0)
	{
		a->img_3d.addr[(int)pixely * (int)a->win.win_w +
		(int)pixelx] = line.color;
		pixelx += line.deltax;
		pixely += line.deltay;
		--remain_pixels;
	}
	return (0);
}
