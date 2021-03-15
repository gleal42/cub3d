/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 15:32:26 by gleal             #+#    #+#             */
/*   Updated: 2021/03/15 20:41:05 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

int		ftinitnotext(t_adata *a)
{
	a->notext.imgt.ptr = mlx_xpm_file_to_image(a->win.mlx, "../textures/redbrick.xpm", &a->notext.imgt.width, &a->notext.imgt.height); 
	a->notext.imgt.addr = (int *)mlx_get_data_addr(a->notext.imgt.ptr,
	&a->notext.imgt.pixel_bits, &a->notext.imgt.line_bytes, &a->notext.imgt.endian);
	return (0);
}

int		ftinitsotext(t_adata *a)
{
	a->sotext.imgt.ptr = mlx_xpm_file_to_image(a->win.mlx, "../textures/wood.xpm", &a->sotext.imgt.width, &a->sotext.imgt.height); 
	a->sotext.imgt.addr = (int *)mlx_get_data_addr(a->sotext.imgt.ptr,
	&a->sotext.imgt.pixel_bits, &a->sotext.imgt.line_bytes, &a->sotext.imgt.endian);
	return (0);
}

int		ftiniteatext(t_adata *a)
{
	a->eatext.imgt.ptr = mlx_xpm_file_to_image(a->win.mlx, "../textures/redbrick.xpm", &a->eatext.imgt.width, &a->eatext.imgt.height); 
	a->eatext.imgt.addr = (int *)mlx_get_data_addr(a->eatext.imgt.ptr,
	&a->eatext.imgt.pixel_bits, &a->eatext.imgt.line_bytes, &a->eatext.imgt.endian);
	return (0);
}

int		ftinitwetext(t_adata *a)
{
	a->wetext.imgt.ptr = mlx_xpm_file_to_image(a->win.mlx, "../textures/redbrick.xpm", &a->wetext.imgt.width, &a->wetext.imgt.height); 
	a->wetext.imgt.addr = (int *)mlx_get_data_addr(a->wetext.imgt.ptr,
	&a->wetext.imgt.pixel_bits, &a->wetext.imgt.line_bytes, &a->wetext.imgt.endian);
	return (0);
}

int		ftinit_texts(t_adata *a)
{
	ftinitnotext(a);
	ftinitsotext(a);
	ftiniteatext(a);
	ftinitwetext(a);
	return (0);
}

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
