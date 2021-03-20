/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 17:52:40 by gleal             #+#    #+#             */
/*   Updated: 2021/03/20 20:33:18 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

int		is_sprite_stripe(t_item *item, int col_id)
{
	if (col_id >= item->xstart && col_id <= item->xend)
		return (1);
	else
		return (0);
}

int		add_sprites(t_item *items, char **strs, t_adata *a)
{
	int		i;
	int		j;
	int		nbr;

	i = 0;
	j = 0;
	nbr = 0;
	while (strs[i])
	{
		j = 0;
		while (strs[i][j])
		{
			if (strs[i][j] == '2')
			{
				items[nbr].x = (double)(j + 0.5) * a->map.tile_size;
				items[nbr].y = (double)(i + 0.5) * a->map.tile_size;
				ftinittext(a, &items[nbr].imgsp, a->parse.sprite_text);
				nbr++;
			}
			j++;
		}
		i++;
	}
	return (0);
}

int		ft_countsprites(char **strs)
{
	int		i;
	int		j;
	int		counter;

	i = 0;
	j = 0;
	counter = 0;
	while (strs[i])
	{
		j = 0;
		while (strs[i][j])
		{
			if (strs[i][j] == '2')
				counter++;
			j++;
		}
		i++;
	}
	return (counter);
}
