/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initdestroyimg.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 17:03:49 by gleal             #+#    #+#             */
/*   Updated: 2021/03/18 17:05:12 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

int		destroyimg(t_adata *a, t_img *img)
{
	mlx_destroy_image(a->win.mlx, img->ptr);
	img->ptr = 0;
	img->addr = 0;
	return (0);
}

int		ftinit_img_sps(t_item *item, t_adata *a)
{
	item->imgsp.ptr = mlx_xpm_file_to_image(a->win.mlx,
	"../textures/barrel.xpm", &item->imgsp.width, &item->imgsp.height);
	item->imgsp.addr = (int *)mlx_get_data_addr(item->imgsp.ptr,
	&item->imgsp.pixel_bits, &item->imgsp.line_bytes, &item->imgsp.endian);
	return (0);
}

void	ftinit_img_m(t_adata *a)
{
	a->img_m.ptr = mlx_new_image(a->win.mlx, a->map.map_w, a->map.map_h);
	a->img_m.addr = (int *)mlx_get_data_addr(a->img_m.ptr,
	&a->img_m.pixel_bits, &a->img_m.line_bytes, &a->img_m.endian);
}

void	ftinit_img_3d(t_adata *a)
{
	a->img_3d.ptr = mlx_new_image(a->win.mlx, a->win.win_w, a->win.win_h);
	a->img_3d.addr = (int *)mlx_get_data_addr(a->img_3d.ptr,
	&a->img_3d.pixel_bits, &a->img_3d.line_bytes, &a->img_3d.endian);
}
