/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 20:57:10 by gleal             #+#    #+#             */
/*   Updated: 2021/03/22 19:18:37 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

int		draw3dline(double ray_angle, t_ray *ray, t_adata *a, int col_id)
{
	ft_prepare_3d_line(ray_angle, ray, a, col_id);
	line3d(ray, a, ray->text_wallhit);
	return (0);
}

int		draw_comp_circle(int p_w, int p_h, t_adata *a)
{
	if (sqrt(pow(a->joe.x - p_w, 2) + pow(a->joe.y - p_h, 2)) <= a->joe.radius)
		a->img_3d.addr[(p_h * (int)a->win.win_w + p_w)] = 0xb87cb3;
	return (0);
}

int		draw_comp_map(int p_w, int p_h, t_adata *a)
{
	int	cur_x;
	int cur_y;

	cur_x = (int)p_w / a->map.tile_size;
	cur_y = (int)p_h / a->map.tile_size;
	if (cur_x >= (int)ft_strlen(a->map.maptxt[cur_y]))
		return (0);
	else if (a->map.maptxt[cur_y][cur_x] == '1')
		a->img_3d.addr[(int)(p_h * (int)a->win.win_w + p_w)] = 0x85b569;
	else if (ft_strchr("02NSWE", a->map.maptxt[cur_y][cur_x]))
		a->img_3d.addr[(int)(p_h * (int)a->win.win_w + p_w)] = 0xebdbb7;
	else
		return (0);
	return (1);
}

int		draw_comp(t_adata *a, int (*comp)(int, int, t_adata *))
{
	int	pixel_w;
	int	pixel_h;

	pixel_h = 0;
	while (pixel_h < a->map.map_h)
	{
		pixel_w = 0;
		while (pixel_w < a->map.map_w)
		{
			comp(pixel_w, pixel_h, a);
			pixel_w++;
		}
		pixel_h++;
	}
	return (0);
}

int		draw_map(t_adata *a)
{
	draw_comp(a, &draw_comp_map);
	draw_comp(a, &draw_comp_circle);
	ft_initline(a);
	line(a->line, a);
	return (0);
}
