/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 19:02:02 by gleal             #+#    #+#             */
/*   Updated: 2021/03/20 19:56:44 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	ft_update_player(t_adata *a)
{
	double	movestep;
	double	next_playerx;
	double	next_playery;

	a->joe.rotangle = normalrad(a->joe.rotangle +
	(a->joe.turndir * a->joe.rotatespeed));
	movestep = a->joe.walkdir * a->joe.movespeed * a->map.tile_size;
	next_playerx = a->joe.x + (cos(a->joe.rotangle) * movestep);
	next_playery = a->joe.y + (sin(a->joe.rotangle) * movestep);
	if (!has_wall(next_playerx, next_playery, a))
	{
		a->joe.x = next_playerx;
		a->joe.y = next_playery;
	}
}
