/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 19:02:02 by gleal             #+#    #+#             */
/*   Updated: 2021/03/15 14:17:55 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

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

double	normalrad(double movestep)
{
	if (movestep >= (2 * M_PI))
		movestep -= (2 * M_PI);
	if (movestep < (0))
		movestep += (2 * M_PI);
	return (movestep);
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
