/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 16:36:09 by gleal             #+#    #+#             */
/*   Updated: 2021/03/13 22:04:19 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

int		ray_construct(double ray_angle, t_ray *ray, t_adata *a)
{
	ray->wallhit_x = 0;
	ray->wallhit_y = 0;
	ray->size = 0;
	if (ray_angle > 0 && ray_angle < M_PI)
		ray->facing_down = 1;
	else
		ray->facing_down = 0;
	if (ray_angle > M_PI_2 && ray_angle < (3 * M_PI_2))
		ray->facing_left = 1;
	else
		ray->facing_left = 0;
	return (0);
}


/*double	vertical_cast(double ray_angle, t_ray *ray, t_adata *a)
{

}*/

int		horizontal_cast(double ray_angle, t_ray *ray, t_adata *a)
{
	double	nexttouch_hx;
	double	nexttouch_hy;

	ray->intercept_y = floor(a->joe.y / a->map.tile_size) * a->map.tile_size;
	if (ray->facing_down)
		ray->intercept_y += a->map.tile_size;
	ray->intercept_x = a->joe.x + ((a->ray.intercept_y - a->joe.y) / tan(ray_angle));
	ray->ystep = a->map.tile_size;
	if (ray->facing_down == 0)
		ray->ystep *= -1;
	ray->xstep = a->map.tile_size / tan(ray_angle);
	if (ray->facing_left && ray->xstep > 0)
		ray->xstep *= -1;
	if (ray->facing_left == 0 && ray->xstep < 0)
		ray->xstep *= -1;

	nexttouch_hx = ray->intercept_x;
	nexttouch_hy = ray->intercept_y;

	if (!ray->facing_down)
		nexttouch_hy--;

	while (nexttouch_hx >= 0 && nexttouch_hx <= a->map.map_w &&
			nexttouch_hy >= 0 && nexttouch_hy <= a->map.map_h)
	{
		if (has_wall(nexttouch_hx, nexttouch_hy, a))
		{
			ray->wall_hit_x = nexttouch_hx;
			ray->wall_hit_y = nexttouch_hy;
			break;
		}
		else
		{
			nexttouch_hx += ray->xstep;
			nexttouch_hy += ray->ystep;
		}
	}
	return (0);
}

/*int		ray_cast(double ray_angle, t_ray *ray, t_adata *a)
{

}*/

int		ft_prepare_ray_line(double ray_angle, t_ray *ray, t_adata *a)
{
	ray->line.start_x = a->joe.x;
	ray->line.start_y = a->joe.y;
	ray->line.end_x = ray->wall_hit_x;
	ray->line.end_y = ray->wall_hit_y;
	ray->line.deltax = ray->line.end_x - ray->line.start_x;
	ray->line.deltay = ray->line.end_y - ray->line.start_y;
	ray->line.pixels = sqrt(pow(ray->line.deltax, 2) + pow(ray->line.deltay, 2));
	ray->line.deltax /= ray->line.pixels;
	ray->line.deltay /= ray->line.pixels;
	ray->line.color = 0xedbc4b;
	return (0);
}

int		cast_all_rays(t_adata *a)
{
	t_ray	ray;
	int col_id;
	double ray_angle;

	col_id = 0;
	ray_angle = normalrad(a->joe.rotangle - (a->ray.fov / 2));

	while (col_id < a->ray.num_rays)
	{
		ray_construct(ray_angle, &ray, a);
		horizontal_cast(ray_angle, &ray, a);
		ft_prepare_ray_line(ray_angle, &ray, a);
		line(ray.line, a);
		ray_angle = normalrad(ray_angle + (a->ray.fov /a->ray.num_rays)); 
		col_id++;
	}
	return (0);
}
