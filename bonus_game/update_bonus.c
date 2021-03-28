/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 21:45:24 by gleal             #+#    #+#             */
/*   Updated: 2021/03/28 21:45:36 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonuscub.h"

void	update_position(t_adata *a)
{
	double	movestep;
	double	next_playerx;
	double	next_playery;
	double	move_angle;

	if (a->joe.walkdir == 0)
		return ;
	move_angle = a->joe.rotangle;
	if (a->joe.walkdir == 'w')
		move_angle = normalrad(move_angle);
	else if (a->joe.walkdir == 's')
		move_angle = normalrad(move_angle + M_PI);
	else if (a->joe.walkdir == 'a')
		move_angle = normalrad(move_angle - M_PI_2);
	else if (a->joe.walkdir == 'd')
		move_angle = normalrad(move_angle + M_PI_2);
	movestep = a->joe.movespeed * a->map.tile_size;
	next_playerx = a->joe.x + (cos(move_angle) * movestep);
	next_playery = a->joe.y + (sin(move_angle) * movestep);
	if (!has_wall(next_playerx, next_playery, a))
	{
		a->joe.x = next_playerx;
		a->joe.y = next_playery;
	}
}

void	update_orientation(t_adata *a)
{
	if (a->joe.turndir == 0)
		return ;
	a->joe.rotangle = normalrad(a->joe.rotangle +
	(a->joe.turndir * a->joe.rotatespeed));
}

void	ft_update_player(t_adata *a)
{
	update_orientation(a);
	update_position(a);
}
