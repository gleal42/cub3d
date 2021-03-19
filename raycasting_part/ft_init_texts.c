/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_texts.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 16:44:59 by gleal             #+#    #+#             */
/*   Updated: 2021/03/19 20:43:28 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

int		ftinitnotext(t_adata *a)
{
	t_text	notext;

	notext.imgt.ptr = mlx_xpm_file_to_image(a->win.mlx,
	"./textures/redbrick.xpm", &notext.imgt.width, &notext.imgt.height);
	notext.imgt.addr = (int *)mlx_get_data_addr(notext.imgt.ptr,
	&notext.imgt.pixel_bits, &notext.imgt.line_bytes,
	&notext.imgt.endian);
	a->notext = notext;
	return (0);
}

int		ftinitsotext(t_adata *a)
{
	t_text	sotext;

	sotext.imgt.ptr = mlx_xpm_file_to_image(a->win.mlx,
	"./textures/wood.xpm", &sotext.imgt.width, &sotext.imgt.height);
	sotext.imgt.addr = (int *)mlx_get_data_addr(sotext.imgt.ptr,
	&sotext.imgt.pixel_bits, &sotext.imgt.line_bytes,
	&sotext.imgt.endian);
	a->sotext = sotext;
	return (0);
}

int		ftiniteatext(t_adata *a)
{
	t_text eatext;

	eatext.imgt.ptr = mlx_xpm_file_to_image(a->win.mlx,
	"./textures/redbrick.xpm", &eatext.imgt.width,
	&eatext.imgt.height);
	eatext.imgt.addr = (int *)mlx_get_data_addr(eatext.imgt.ptr,
	&eatext.imgt.pixel_bits, &eatext.imgt.line_bytes,
	&eatext.imgt.endian);
	a->eatext = eatext;
	return (0);
}

int		ftinitwetext(t_adata *a)
{
	t_text wetext;

	wetext.imgt.ptr = mlx_xpm_file_to_image(a->win.mlx,
	"./textures/redbrick.xpm", &wetext.imgt.width,
	&wetext.imgt.height);
	wetext.imgt.addr = (int *)mlx_get_data_addr(wetext.imgt.ptr,
	&wetext.imgt.pixel_bits, &wetext.imgt.line_bytes,
	&wetext.imgt.endian);
	a->wetext = wetext;
	return (0);
}
