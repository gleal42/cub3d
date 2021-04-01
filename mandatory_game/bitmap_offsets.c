/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap_offsets.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 17:27:38 by gleal             #+#    #+#             */
/*   Updated: 2021/04/01 00:30:20 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "start_game.h"
/* before I calculated the beginning and end of each sprite on the screen. as well as their width
So if the col_id / width x strip is the same as the start we will assign them the start of the sprite texture */
int		bitmap_offset_sp(t_item *item, int col_id)
{
	double	remainder;
	double	offset;

	remainder = (double)(((double)col_id - item->xstart) / item->sprite_w);
	offset = (item->imgsp.width - 1) * remainder;
	return (offset);
}
/* Here I converted the map_tile_size to 1 so that we could use the floor function to calculate the right part of the texture
E.g. If we were in x = 5 and tile size is 2. After conversion x = 2.5. Floor (2.5) = 2
2.5 - 2 = 0.5 so we are pointing at the middle of the texture.  */
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
