/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap_offsets.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 17:27:38 by gleal             #+#    #+#             */
/*   Updated: 2021/03/25 15:02:25 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

int		bitmap_offset_floor(t_adata *a, double *x, double *y)
{
	while (*x >= 1)
		(*x)--;
	while (*y >= 1)
		(*y)--;
	if (*x >= 0)
		*x = *x * a->wetext.imgt.width;
	if (*y >= 0)
		*y = *y * a->wetext.imgt.height;
	return (0);
}

int		bitmap_offset_sp(t_item *item, int col_id)
{
	double	remainder;
	double	offset;

	remainder = (double)(((double)col_id - item->xstart) / item->sprite_w);
	offset = item->imgsp.width * remainder;
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
		offset = a->sotext.imgt.width * remainder;
	}
	else
	{
		remainder = ray_x - floor(ray_x);
		offset = a->sotext.imgt.width * remainder;
	}
	return (offset);
}
