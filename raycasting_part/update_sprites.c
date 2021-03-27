/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 18:32:47 by gleal             #+#    #+#             */
/*   Updated: 2021/03/27 18:19:20 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

int		spritescreenposition(t_item *item, t_adata *a)
{
	double	centersprite;

	item->sprite_w = ((item->imgsp.width / item->imgsp.height) *
	a->ray.distprojplane) * 0.8 /
	(item->distance / a->map.tile_size);
	item->sprite_h = a->ray.distprojplane * 0.8 /
	(item->distance / a->map.tile_size);
	item->ystart = a->win.win_h / 2 -
	(item->sprite_h / 2);
	item->yend = item->ystart + item->sprite_h;
	centersprite = tan(item->angle) * a->ray.distprojplane;
	item->xstart = a->win.win_w / 2 + centersprite - item->sprite_w / 2;
	item->xend = item->xstart + item->sprite_w;
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
	int		further;
	int		check;
	t_item	swap;

	check = 0;
	further = 0;
	while (further < a->sps.number)
	{
		check = further + 1;
		while (check < a->sps.number)
		{
			if (items[check].distance > items[further].distance)
			{
				swap = items[further];
				items[further] = items[check];
				items[check] = swap;
			}
			check++;
		}
		further++;
	}
	return (0);
}

int		update_info_sps(t_item **item, t_adata *a)
{
	int			i;
	double		sp_anglemap;
	double		vetx;
	double		vety;

	i = 0;
	while (i < a->sps.number)
	{
		vetx = (*item)[i].x - a->joe.x;
		vety = (*item)[i].y - a->joe.y;
		sp_anglemap = normalrad(atan2(vety, vetx));
		(*item)[i].angle = normalrad(sp_anglemap - a->joe.rotangle);
		if (((*item)[i].angle > a->ray.fovref_min &&
		(*item)[i].angle < 2 * M_PI) ||
		((*item)[i].angle >= 0 && (*item)[i].angle < a->ray.fovref_max))
			(*item)[i].is_visible = 1;
		else
			(*item)[i].is_visible = 0;
		(*item)[i].distance = (double)(sqrt(pow(vetx, 2) + pow(vety, 2)));
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
