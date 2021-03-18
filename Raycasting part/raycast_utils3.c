/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 17:52:40 by gleal             #+#    #+#             */
/*   Updated: 2021/03/18 18:33:53 by gleal            ###   ########.fr       */
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
