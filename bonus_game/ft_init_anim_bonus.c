/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_anim.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 21:42:11 by gleal             #+#    #+#             */
/*   Updated: 2021/03/29 17:38:00 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonuscub.h"

void	ft_init_animation(t_adata *a)
{
	a->joe.anim_start = 0;
	a->joe.anim_count = 0;
	a->map.map_r_half = ceil((double)(a->win.win_w / 2));
	a->map.map_b_half = ceil((double)(a->win.win_h / 2));
}
