/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 16:36:09 by gleal             #+#    #+#             */
/*   Updated: 2021/03/21 17:24:57 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

int		ray_construct(double ray_angle, t_ray *ray)
{
	ray->wall_hit_horx = 0;
	ray->wall_hit_hory = 0;
	ray->wall_hit_verx = 0;
	ray->wall_hit_very = 0;
	ray->wall_hit_x = 0;
	ray->wall_hit_y = 0;
	ray->found_hor_wall = 0;
	ray->found_ver_wall = 0;
	ray->hit_vertical = 0;
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

int		vertical_cast(t_ray *ray, t_adata *a)
{
	double	nexttouch_verx;
	double	nexttouch_very;

	vertical_interstep(a, ray, &nexttouch_verx, &nexttouch_very);
	vertical_cast_facingleft(a, ray, &nexttouch_verx, &nexttouch_very);
	vertical_cast_facingright(a, ray, &nexttouch_verx, &nexttouch_very);
	return (0);
}

int		horizontal_cast(t_ray *ray, t_adata *a)
{
	double	nexttouch_horx;
	double	nexttouch_hory;

	horizontal_interstep(a, ray, &nexttouch_horx, &nexttouch_hory);
	horizontal_cast_facingup(a, ray, &nexttouch_horx, &nexttouch_hory);
	horizontal_cast_facingdown(a, ray, &nexttouch_horx, &nexttouch_hory);
	return (0);
}

int		dda_alg(t_ray *ray, t_adata *a)
{
	double horz_dist;
	double vert_dist;

	horizontal_cast(ray, a);
	vertical_cast(ray, a);
	horiz_vert_raycomp(a, ray, &horz_dist, &vert_dist);
	return (0);
}

int		draw3d(t_adata *a)
{
	t_ray	ray;
	int		col_id;

	col_id = 0;
	ray.ray_angle = normalrad(a->joe.rotangle - (a->ray.fov / 2));
	while (col_id < a->ray.num_rays)
	{
		ray_construct(ray.ray_angle, &ray);
		dda_alg(&ray, a);
		ft_prepare_ray_line(&ray, a);
		line(ray.line, a);
		draw3dline(ray.ray_angle, &ray, a, col_id);
		drawsps(&ray, a, col_id);
		ray.ray_angle = normalrad(ray.ray_angle
		+ (a->ray.fov / a->ray.num_rays));
		col_id++;
	}
	return (0);
}
