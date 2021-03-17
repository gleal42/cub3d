/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 19:02:02 by gleal             #+#    #+#             */
/*   Updated: 2021/03/17 20:32:03 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

int		spritescreenposition(t_item *item, t_adata *a)
{
	double	centersprite;

	item->sprite_hw = a->ray.distprojplane/item->distance;
	item->ystart = a->map.map_h/2 - item->sprite_hw/2;
	item->yend = item->ystart + item->sprite_hw;
	centersprite = tan(item->angle) * a->ray.distprojplane;
	item->xstart = a->map.map_w/2 + centersprite - item->sprite_hw/2;
	item->xend = item->xstart + item->sprite_hw;
	return (0);
}

int		sps_pos_on_screen(t_item *item, t_adata *a)
{
	int		i;

	i = 0;
	while (i < a->sps.number)
	{
		if (item[i].is_visible)
			spritescreenposition(&item[i], a);
		i++;
	}
	return (0);
}

int		sort_sps(t_item *items, t_adata *a)
{
	int smaller;
	int check;
	t_item	swap;

	check = 0;
	smaller = 0;
	while (smaller < a->sps.number)
	{
		check = smaller + 1;
		while (check < a->sps.number)
		{
			if (items[check].distance < items[smaller].distance)
			{
				swap = items[smaller];
				items[smaller] = items[check];
				items[check] = swap;
			}
			check++;
		}
		smaller++;
	}
	return (0);
}

int		update_info_sps(t_item **item, t_adata *a)
{
	int i;
	double sp_anglemap;
	double fovref_min;
	double fovref_max;
	double		vetx;
	double		vety;

	fovref_min = 2 * M_PI - (a->ray.fov/2);
	fovref_max = a->ray.fov/2;
	i = 0;
	while (i < a->sps.number)
	{
		vetx = (*item)[i].x - a->joe.x;
		vety = (*item)[i].y - a->joe.y;
		sp_anglemap = normalrad(atan2(vety, vetx));
		(*item)[i].angle = normalrad(a->joe.rotangle - sp_anglemap);
		if (((*item)[i].angle > fovref_min && (*item)[i].angle < 2*M_PI) ||
				((*item)[i].angle >= 0 && (*item)[i].angle < fovref_max))
			(*item)[i].is_visible = 1;
		else
			(*item)[i].is_visible = 0;
		(*item)[i].distance = (double)(sqrt(pow(vetx, 2) + pow(vety, 2)/
					a->map.tile_size));
		i++;
	}
	return (0);
}

int		update_sprites(t_adata *a)
{
	update_info_sps(&a->sps.items, a);
	sort_sps(a->sps.items, a);
	sps_pos_on_screen(a->sps.items, a);
	return (0);
}

int		has_wall(double x, double y, t_adata *a)
{
	int mapgridx;
	int mapgridy;

	if (x < 0 || x > a->map.map_w || y < 0 || y > a->map.map_h)
		return (1);
	mapgridx = floor(x / a->map.tile_size);
	mapgridy = floor(y / a->map.tile_size);
	if (a->map.maptxt[mapgridy][mapgridx] == '1')
		return (1);
	return (0);
}

void	ft_update(t_adata *a)
{
	double	movestep;
	double	next_playerx;
	double	next_playery;

	a->joe.rotangle = normalrad(a->joe.rotangle + (a->joe.turndir * a->joe.rotatespeed));
	movestep = a->joe.walkdir * a->joe.movespeed;
	next_playerx = a->joe.x + (cos(a->joe.rotangle) * movestep);
	next_playery = a->joe.y + (sin(a->joe.rotangle) * movestep);

	if (!has_wall(next_playerx, next_playery, a))
	{
		a->joe.x = next_playerx;
		a->joe.y = next_playery;
	}
}
