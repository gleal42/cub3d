/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 17:40:35 by gleal             #+#    #+#             */
/*   Updated: 2021/03/28 15:54:18 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "start_game.h"

int		ftinit_sprites(t_adata *a)
{
	a->sps.number = ft_countsprites(a->map.maptxt);
	a->sps.items = malloc(sizeof(t_item) * (a->sps.number));
	add_sprites(a->sps.items, a->map.maptxt, a);
	return (0);
}

int		ftinit_texts(t_adata *a)
{
	ftinittext(a, &a->notext.imgt, a->parse.no_text);
	ftinittext(a, &a->sotext.imgt, a->parse.so_text);
	ftinittext(a, &a->wetext.imgt, a->parse.we_text);
	ftinittext(a, &a->eatext.imgt, a->parse.ea_text);
	return (0);
}

void	ftinit_player(t_adata *a)
{
	ft_playerinfo(&a->map, &a->joe, a->map.maptxt);
	a->joe.radius = a->map.tile_size / 6;
	a->joe.turndir = 0;
	a->joe.walkdir = 0;
	a->joe.movespeed = 0.35;
	a->joe.rotatespeed = 7 * (M_PI / 180);
}

void	ftinit_map(t_adata *a)
{
	a->map.maptxt = a->parse.mapstr;
	a->map.map_rows = ft_count_lines(a->map.maptxt);
	a->map.map_cols = ft_max_strlen(a->map.maptxt);
	a->map.tile_size = calculate_tilesize(a);
	a->map.map_h = a->map.map_rows * a->map.tile_size;
	a->map.map_w = a->map.map_cols * a->map.tile_size;
}

void	ftinit_win(t_adata *a)
{
	a->win.mlx = mlx_init();
	a->win.win_w = a->parse.rx;
	a->win.win_h = a->parse.ry;
	a->win.win = mlx_new_window(a->win.mlx, a->win.win_w,
	a->win.win_h, "Wolfenstein3D");
}
