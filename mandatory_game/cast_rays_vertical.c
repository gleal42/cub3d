/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays_vertical.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 15:58:10 by gleal             #+#    #+#             */
/*   Updated: 2021/03/28 15:54:18 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "start_game.h"

int		vertical_cast_facingright(t_adata *a, t_ray *ray,
		double *nexttouch_verx, double *nexttouch_very)
{
	if (!ray->facing_left)
	{
		while (*nexttouch_verx >= 0 && (*nexttouch_verx) < a->map.map_w - 1 &&
			*nexttouch_very >= 0 && (*nexttouch_very) < a->map.map_h - 1)
		{
			if (has_wall((*nexttouch_verx) + 1, *nexttouch_very, a))
			{
				ray->found_ver_wall = 1;
				ray->wall_hit_verx = *nexttouch_verx;
				ray->wall_hit_very = *nexttouch_very;
				return (0);
			}
			else
			{
				*nexttouch_verx += ray->verxstep;
				*nexttouch_very += ray->verystep;
			}
		}
	}
	return (0);
}

int		vertical_cast_facingleft(t_adata *a, t_ray *ray,
		double *nexttouch_verx, double *nexttouch_very)
{
	if (ray->facing_left)
	{
		while (*nexttouch_verx >= 0 && *nexttouch_verx < a->map.map_w &&
			*nexttouch_very >= 0 && *nexttouch_very < a->map.map_h)
		{
			if (has_wall((*nexttouch_verx) - 1, *nexttouch_very, a))
			{
				ray->found_ver_wall = 1;
				ray->wall_hit_verx = *nexttouch_verx;
				ray->wall_hit_very = *nexttouch_very;
				break ;
			}
			else
			{
				*nexttouch_verx += ray->verxstep;
				*nexttouch_very += ray->verystep;
			}
		}
	}
	return (0);
}

int		vertical_interstep(t_adata *a, t_ray *ray,
		double *nexttouch_verx, double *nexttouch_very)
{
	double	inter_y;
	double	inter_x;

	inter_x = floor(a->joe.x / a->map.tile_size) * a->map.tile_size;
	if (!ray->facing_left)
		inter_x += a->map.tile_size;
	inter_y = a->joe.y + ((inter_x - a->joe.x) * tan(ray->ray_angle));
	ray->verxstep = a->map.tile_size;
	if (ray->facing_left)
		ray->verxstep *= -1;
	ray->verystep = a->map.tile_size * tan(ray->ray_angle);
	if (!ray->facing_down && ray->verystep > 0)
		ray->verystep *= -1;
	if (ray->facing_down && ray->verystep < 0)
		ray->verystep *= -1;
	*nexttouch_verx = inter_x;
	*nexttouch_very = inter_y;
	return (0);
}
