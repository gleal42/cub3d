/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horiz_vert_raycomp.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 16:01:04 by gleal             #+#    #+#             */
/*   Updated: 2021/03/27 20:03:04 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./start_game.h"

void	horiz_vert_raycomp(t_adata *a, t_ray *ray,
		double *horz_dist, double *vert_dist)
{
	if (ray->found_hor_wall)
		*horz_dist = distancepoints(a->joe.x, a->joe.y,
		ray->wall_hit_horx, ray->wall_hit_hory);
	else
		*horz_dist = INT_MAX;
	if (ray->found_ver_wall)
		*vert_dist = distancepoints(a->joe.x, a->joe.y,
		ray->wall_hit_verx, ray->wall_hit_very);
	else
		*vert_dist = INT_MAX;
	if (*horz_dist < *vert_dist)
	{
		ray->wall_hit_x = ray->wall_hit_horx;
		ray->wall_hit_y = ray->wall_hit_hory;
		ray->distance = *horz_dist;
		ray->hit_vertical = 0;
	}
	else
	{
		ray->wall_hit_x = ray->wall_hit_verx;
		ray->wall_hit_y = ray->wall_hit_very;
		ray->distance = *vert_dist;
		ray->hit_vertical = 1;
	}
}
