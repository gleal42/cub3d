/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap_offsets.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 17:27:38 by gleal             #+#    #+#             */
/*   Updated: 2021/03/29 20:14:46 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "start_game.h"

int		bitmap_offset_sp(t_item *item, int col_id)
{
	double	remainder;
	double	offset;

	remainder = (double)(((double)col_id - item->xstart) / item->sprite_w);
	offset = (item->imgsp.width - 1) * remainder;
	return (offset);
}

int		bitmap_offset(t_ray *ray, t_adata *a)
{
	double	ray_x;
	double	ray_y;
	double	remainder;
	int		offset;

	ray_x = ray->wall_hit_x / a->map.tile_size;
	ray_y = ray->wall_hit_y / a->map.tile_size;
	if (ray->hit_vertical)
	{
		remainder = ray_y - floor(ray_y);
		offset = (ray->text_wallhit.imgt.width - 1) * remainder;
	}
	else
	{
		remainder = ray_x - floor(ray_x);
		offset = (ray->text_wallhit.imgt.width - 1) * remainder;
	}
	return (offset);
}
