/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 20:57:10 by gleal             #+#    #+#             */
/*   Updated: 2021/03/18 18:51:31 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

int		draw3dline(double ray_angle, t_ray *ray, t_adata *a, int col_id)
{
	ft_prepare_3d_line(ray_angle, ray, a, col_id);
	line3d(ray_angle, ray, a, col_id);
	return (0);
}

int		draw_comp_circle(int p_w, int p_h, t_adata *a)
{
	if (sqrt(pow(a->joe.x - p_w, 2) + pow(a->joe.y - p_h, 2)) <= a->joe.radius)
		a->img_m.addr[(p_h * a->map.map_w + p_w)] = 0xb87cb3;
	return (0);
}

int		draw_minicircle(t_adata *a)
{
	int	pixel_w;
	int	pixel_h;

	pixel_h = 0;
	while (pixel_h < a->map.map_h)
	{
		pixel_w = 0;
		while (pixel_w < a->map.map_w)
		{
			draw_comp_circle(pixel_w, pixel_h, a);
			pixel_w++;
		}
		pixel_h++;
	}
	return (0);
}

int		draw_comp_map(int p_w, int p_h, t_adata *a)
{
	int	cur_x;
	int cur_y;

	cur_x = (int)p_w / a->map.tile_size;
	cur_y = (int)p_h / a->map.tile_size;
	if (cur_x >= ft_strlen(a->map.maptxt[cur_y]))
		a->img_m.addr[(int)(p_h * a->map.map_w + p_w)] = 0xD6D6D6;
	else if (a->map.maptxt[cur_y][cur_x] == '1')
		a->img_m.addr[(int)(p_h * a->map.map_w + p_w)] = 0x85b569;
	else if (ft_strchr("02NSWE", a->map.maptxt[cur_y][cur_x]))
		a->img_m.addr[(int)(p_h * a->map.map_w + p_w)] = 0xebdbb7;
	else
		a->img_m.addr[(int)(p_h * a->map.map_w + p_w)] = 0xD6D6D6;
	return (0);
}

int		draw_map(t_adata *a)
{
	int	pixel_w;
	int	pixel_h;

	pixel_h = 0;
	while (pixel_h < a->map.map_h)
	{
		pixel_w = 0;
		while (pixel_w < a->map.map_w)
		{
			draw_comp_map(pixel_w, pixel_h, a);
			pixel_w++;
		}
		pixel_h++;
	}
	return (0);
}
