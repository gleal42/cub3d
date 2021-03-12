/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 16:36:09 by gleal             #+#    #+#             */
/*   Updated: 2021/03/12 18:32:41 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

int		ft_next_ray(double ray_angle, t_ray *ray, t_adata *a)
{
	ray->line.start_x = a->joe.x;
	ray->line.start_y = a->joe.y;
	ray->line.end_x = a->joe.x + (cos(ray_angle) * 30);
	ray->line.end_y = a->joe.y + (sin(ray_angle) * 30);
	ray->line.deltax = ray->line.end_x - ray->line.start_x;
	ray->line.deltay = ray->line.end_y - ray->line.start_y;
	ray->line.pixels = sqrt(pow(ray->line.deltax, 2) + pow(ray->line.deltay, 2));
	ray->line.deltax /= ray->line.pixels;
	ray->line.deltay /= ray->line.pixels;
	ray->line.color = 0xedbc4b;
	return (0);
}

int		cast_rays(t_adata *a)
{
	t_ray	ray;
	int col_id;
	double ray_angle;

	col_id = 0;
	ray_angle = a->joe.rotangle - (a->ray.fov / 2);

	while (col_id < a->ray.num_rays)
	{
		ft_next_ray(ray_angle, &ray, a);
		line(ray.line, a);
		ray_angle += a->ray.fov /a->ray.num_rays; 
		col_id++;
	}
	return (0);
}
