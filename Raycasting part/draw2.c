/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 21:51:03 by gleal             #+#    #+#             */
/*   Updated: 2021/03/19 16:33:58 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

int		drawsps(t_ray *ray, t_adata *a, int col_id)
{
	int		i;

	i = 0;
	while (i < a->sps.number)
	{
		if ((a->sps.items[i]).is_visible &&
		is_sprite_stripe(&a->sps.items[i], col_id)
		&& ray->distance > a->sps.items[i].distance
		&& a->sps.items[i].xstart > 0 && a->sps.items[i].xend < a->win.win_w)
		{
			ft_prepare_sprite_line(&a->sps.items[i], a, col_id);
			linesprite(&a->sps.items[i], a, col_id);
		}
		i++;
	}
	return (0);
}
