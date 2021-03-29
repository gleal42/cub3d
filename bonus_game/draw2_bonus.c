/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 17:28:05 by gleal             #+#    #+#             */
/*   Updated: 2021/03/29 16:24:04 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonuscub.h"

void	pickaxe_animation(t_adata *a)
{
	double		p_w;
	double		p_h;
	double		start_w;
	double		start_h;
	int			m_y;
	int			m_x;

	start_w = ceil((double)(a->win.win_w / 2));
	start_h = ceil((double)(a->win.win_h / 2));
	p_h = start_h;
	while ((int)p_h < a->win.win_h)
	{
		p_w = start_w;
		while ((int)p_w < a->win.win_w)
		{
			m_y = calc_texy(p_h - start_h, a->win.win_h - 1 - start_h, a);
			m_x = calc_texx(p_w - start_w, a->win.win_w - 1 - start_w, a);
			if (a->wetext.imgt.addr [m_y * a->wetext.imgt.width + m_x])
			{
				a->img_3d.addr[(int)(int)p_h * (int)a->win.win_w + (int)p_w] =
				a->wetext.imgt.addr [m_y * a->wetext.imgt.width + m_x];
			}
			p_w++;
		}
		p_h++;
	}
 }

int		drawfloortxt(t_ray *ray, t_adata *a, int col_id)
{
	double		column_angle;
	int			row;
	double		x;
	double		y;
	double		distance;

	column_angle = normalrad(ray->ray_angle - a->joe.rotangle);
	row = a->line_3d.end_y + 1;
	while (row < a->win.win_h)
	{
		distance = ((0.5 / (row - a->win.win_h / 2)) * a->ray.distprojplane) /
		cos(column_angle);
		x = (a->joe.x / a->map.tile_size) + (distance * cos(ray->ray_angle));
		y = (a->joe.y / a->map.tile_size) + (distance * sin(ray->ray_angle));
		bitmap_offset_floor(a, &x, &y);
		if (x >= a->sotext.imgt.width)
			x = a->sotext.imgt.width - 1.0;
		if (y >= a->sotext.imgt.height)
			y = a->sotext.imgt.height - 1.0;
		a->img_3d.addr[(row * (int)a->win.win_w + col_id)] =
		a->sotext.imgt.addr[(int)y * a->sotext.imgt.width + (int)x];
		row++;
	}
	return (0);
}

int		draw_ceilingrgb(t_adata *a)
{
	int			p_w;
	int			p_h;
	double		adjust_height_half;

	adjust_height_half = ceil((double)(a->win.win_h / 2)) - 1;
	p_h = 0;
	while (p_h < (int)adjust_height_half)
	{
		p_w = 0;
		while (p_w < a->win.win_w)
		{
			a->img_3d.addr[(int)(p_h * a->win.win_w + p_w)] =
			create_trgb(0, a->parse.rceil,
			a->parse.gceil, a->parse.bceil);
			p_w++;
		}
		p_h++;
	}
	return (0);
}

int		drawsps(t_ray *ray, t_adata *a, int col_id)
{
	int		i;

	i = 0;
	while (i < a->sps.number)
	{
		if ((a->sps.items[i]).is_visible &&
		is_sprite_stripe(&a->sps.items[i], col_id)
		&& ray->distance > a->sps.items[i].distance
		&& a->sps.items[i].xstart > 0 && a->sps.items[i].xend < a->win.win_w)
		{
			ft_prepare_sprite_line(&a->sps.items[i], a, col_id);
			linesprite(&a->sps.items[i], a, col_id);
		}
		i++;
	}
	return (0);
}
