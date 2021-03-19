/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays_horizontal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 15:56:05 by gleal             #+#    #+#             */
/*   Updated: 2021/03/19 15:56:38 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

int		horizontal_cast_facingdown(t_adata *a, t_ray *ray,
		double *nexttouch_horx, double *nexttouch_hory)
{
	if (ray->facing_down)
	{
		while (*nexttouch_horx >= 0 && *nexttouch_horx <= a->map.map_w &&
			*nexttouch_hory >= 0 && *nexttouch_hory <= a->map.map_h)
		{
			if (has_wall(*nexttouch_horx, *nexttouch_hory + 1, a))
			{
				ray->found_hor_wall = 1;
				ray->wall_hit_horx = *nexttouch_horx;
				ray->wall_hit_hory = *nexttouch_hory;
				break ;
			}
			else
			{
				*nexttouch_horx += ray->horxstep;
				*nexttouch_hory += ray->horystep;
			}
		}
	}
	return (0);
}

int		horizontal_cast_facingup(t_adata *a, t_ray *ray,
		double *nexttouch_horx, double *nexttouch_hory)
{
	if (!ray->facing_down)
	{
		while (*nexttouch_horx >= 0 && *nexttouch_horx <= a->map.map_w &&
			*nexttouch_hory >= 0 && *nexttouch_hory <= a->map.map_h)
		{
			if (has_wall(*nexttouch_horx, *nexttouch_hory - 1, a))
			{
				ray->found_hor_wall = 1;
				ray->wall_hit_horx = *nexttouch_horx;
				ray->wall_hit_hory = *nexttouch_hory;
				break ;
			}
			else
			{
				*nexttouch_horx += ray->horxstep;
				*nexttouch_hory += ray->horystep;
			}
		}
	}
	return (0);
}

int		horizontal_interstep(t_adata *a, t_ray *ray,
		double *nexttouch_horx, double *nexttouch_hory)
{
	double	inter_y;
	double	inter_x;

	inter_y = floor(a->joe.y / a->map.tile_size) * a->map.tile_size;
	if (ray->facing_down)
		inter_y += a->map.tile_size;
	inter_x = a->joe.x + ((inter_y - a->joe.y) / tan(ray->ray_angle));
	ray->horystep = a->map.tile_size;
	if (!ray->facing_down)
		ray->horystep *= -1;
	ray->horxstep = a->map.tile_size / tan(ray->ray_angle);
	if (ray->facing_left && ray->horxstep > 0)
		ray->horxstep *= -1;
	if (!ray->facing_left && ray->horxstep < 0)
		ray->horxstep *= -1;
	*nexttouch_horx = inter_x;
	*nexttouch_hory = inter_y;
	return (0);
}
