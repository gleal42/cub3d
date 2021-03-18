/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 18:44:15 by gleal             #+#    #+#             */
/*   Updated: 2021/03/18 21:45:43 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

int		vertical_interstep(t_adata *a, t_ray *ray, double *nexttouch_verx, double *nexttouch_very)
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

int		horizontal_interstep(t_adata *a, t_ray *ray, double *nexttouch_horx, double *nexttouch_hory)
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
