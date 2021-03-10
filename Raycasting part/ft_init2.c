/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 15:32:26 by gleal             #+#    #+#             */
/*   Updated: 2021/03/10 17:48:24 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	ft_init_dirline(t_adata *a)
{
	t_line	dir_l;

	dir_l.start_x = a->joe.x;  
	dir_l.start_y = a->joe.y;
	dir_l.end_x = dir_l.start_x + cos(a->joe.rotangle) * (a->map.tile_size / 2);
	dir_l.end_y = dir_l.start_y + sin(a->joe.rotangle) * (a->map.tile_size / 2);
	dir_l.color = 0x7cb3b8;
	dir_l.deltax = cos(a->joe.rotangle) * (a->map.tile_size / 2);
	dir_l.deltay = sin(a->joe.rotangle) * (a->map.tile_size / 2) ;
	dir_l.pixels = sqrt(pow(dir_l.deltax, 2) + pow(dir_l.deltay, 2));
	dir_l.deltax /= dir_l.pixels;
	dir_l.deltay /= dir_l.pixels;


	a->dir_l = dir_l;
}
