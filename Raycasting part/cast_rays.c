/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 16:36:09 by gleal             #+#    #+#             */
/*   Updated: 2021/03/12 21:15:43 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

int		ray_construct(double ray_angle, t_ray *ray, t_adata *a)
{
	ray->wallhit_x = 0;
	ray->wallhit_y = 0;
	ray->size = 0;
	if (ray_angle > 0 && ray_angle < M_PI)
		ray->facingdown = 1;
	else
		ray->facingdown = 0;
	if (ray_angle > M_PI_2 && ray_angle < (3 * M_PI_2))
		ray->facingleft = 1;
	else
		ray->facingleft = 0;
	return (0);
}

int		ray_cast(double ray_angle, t_ray *ray, t_adata *a)
{
	ray->intercept_y = floor(a->joe.y / a->map.tile_size) * a->map.tile_size;
	if (ray->facingdown)
		ray->intecept_y += a->map.tile_size;
	ray->intercept_x = a->joe.x + (a->ray.intercept_y - a->joe.y) / tan(ray_angle);
	ray->ystep = a->map.tile_size;
	/*HERE*/
	return (0);
}

int		ft_prepare_ray_line(double ray_angle, t_ray *ray, t_adata *a)
{
	ray->line.start_x = a->joe.x;
	ray->line.start_y = a->joe.y;
	ray->line.end_x = a->joe.x + (cos(ray_angle) * 30/*ray->size*/);
	ray->line.end_y = a->joe.y + (sin(ray_angle) * 30/*ray->size*/);
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
		ray_cast(ray_angle, &ray, a);
		ft_prepare_ray_line(ray_angle, &ray, a);
		line(ray.line, a);
		ray_angle = normalrad(ray_angle + (a->ray.fov /a->ray.num_rays)); 
		col_id++;
	}
	return (0);
}
