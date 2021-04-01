/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_anim_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 21:42:11 by gleal             #+#    #+#             */
/*   Updated: 2021/04/01 00:49:01 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonuscub.h"
/* the map r half and b half are variables that I will use to place the weapons in the right bottom quarter of the screen */
void	ft_init_animation(t_adata *a)
{
	a->joe.anim_start = 0;
	a->joe.anim_count = 0;
	a->map.map_r_half = ceil((double)(a->win.win_w / 2));
	a->map.map_b_half = ceil((double)(a->win.win_h / 2));
}
