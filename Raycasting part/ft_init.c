/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 17:40:35 by gleal             #+#    #+#             */
/*   Updated: 2021/03/17 20:04:13 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

int		add_sprites(t_item *items, char **strs, t_adata *a)
{
	int		i;
	int		j;
	int		nbr;

	i = 0;
	j = 0;
	nbr = 0;
	while(strs[i])
	{
		j = 0;
		while (strs[i][j])
		{
			if (strs[i][j] == '2')
			{
				items[nbr].x = (double)(j + 0.5) * a->map.tile_size;
				items[nbr].y = (double)(i + 0.5) * a->map.tile_size;
				ftinit_img_sps(&items[nbr], a);
				nbr++;
			}
			j++;
		}
		i++;
	}
	return (0);
}

int		ftinit_sprites(t_adata *a)
{
	int		i;

	a->sps.number = ft_countsprites(a->map.maptxt);
	a->sps.items = malloc(sizeof(t_item) * (a->sps.number));
	add_sprites(a->sps.items, a->map.maptxt, a);
	return (0);
}

void	ftinit_player(t_adata *a)
{
	ft_playerinfo(&a->map, &a->joe, a->map.maptxt);
	a->joe.radius = a->map.tile_size / 6;
	a->joe.turndir = 0;
	a->joe.walkdir = 0;
	a->joe.movespeed = 4.0;
	a->joe.rotatespeed = 5 * (M_PI / 180);
}

void	ftinit_img_m(t_adata *a)
{
	a->img_m.ptr = mlx_new_image(a->win.mlx, a->map.map_w, a->map.map_h);
	a->img_m.addr = (int *)mlx_get_data_addr(a->img_m.ptr,
	&a->img_m.pixel_bits, &a->img_m.line_bytes, &a->img_m.endian);
}

void	ftinit_map(t_adata *a)
{
	a->map.maptxt = ft_test_map();
	a->map.map_rows = ft_count_lines(a->map.maptxt);
	a->map.map_cols = ft_max_strlen(a->map.maptxt);
	a->map.tile_size = 18;
	a->map.map_h = a->map.map_rows * a->map.tile_size;
	a->map.map_w = a->map.map_cols * a->map.tile_size;
}

void	ftinit_win(t_adata *a)
{
	t_win		win;

	a->win.mlx = mlx_init();
	a->win.win_w = 1920;
	a->win.win_h = 1080;
	a->win.win = mlx_new_window(a->win.mlx, a->win.win_w, a->win.win_h, "Wolfenstein3D");
}

void	ft_init_all(t_adata *a)
{
	ftinit_win(a);
	ftinit_map(a);
	ftinit_player(a);
	ftinit_texts(a);
	ftinit_rays(a);
	ftinit_sprites(a);
}
