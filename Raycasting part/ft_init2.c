/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 15:32:26 by gleal             #+#    #+#             */
/*   Updated: 2021/03/14 20:47:09 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	ftinit_img_3d(t_adata *a)
{
	a->img_3d.ptr = mlx_new_image(a->win.mlx, a->win.win_w, a->win.win_h);
	a->img_3d.addr = (int *)mlx_get_data_addr(a->img_3d.ptr,
	&a->img_3d.pixel_bits, &a->img_3d.line_bytes, &a->img_3d.endian);
}

void	ftinit_rays(t_adata *a)
{
	a->ray.fov = 60  * (M_PI / 180);
	a->ray.wall_strip_w = 1;
	a->ray.num_rays = a->win.win_w /a->ray.wall_strip_w;
}
