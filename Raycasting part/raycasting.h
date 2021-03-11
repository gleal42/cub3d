/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 19:21:33 by gleal             #+#    #+#             */
/*   Updated: 2021/03/11 19:50:34 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

#include "../cub3d.h"

#define UP_ARROW 126
#define DOWN_ARROW 125
#define LEFT_ARROW 123
#define RIGHT_ARROW 124

typedef struct	s_win
{
	void	*mlx;
	double	win_w;
	double	win_h;
	void	*win;
}				t_win;

typedef struct	s_img
{
	void 	*ptr;
	int		*addr;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
}				t_img;


typedef struct	s_map2d
{
	double	tile_size;
	char	**maptxt;
	int		map_w;
	int		map_h;
	double	map_rows;
	double	map_cols;
}				t_map2d;

typedef struct	s_player
{
	int		x;
	int		y;
	double	radius;
	int		walkdir;
	int		turndir;
	double	rotangle;
	double	movespeed;
	double	rotatespeed;
}				t_player;

typedef struct	s_line
{
	int			start_x;
	int			start_y;
	int			end_x;
	int			end_y;
	int			color;
	double		deltax;
	double		deltay;
	double		pixels;
	double		pixelx;
	double 		pixely;
}				t_line;

typedef struct	s_adata
{
	t_win		win;
	t_map2d		map;;
	t_player	joe;
	t_img		img_m;
	t_line		line;
}				t_adata;

char	**ft_test_map(void);
int		ft_max_strlen(char **strs);
int		ft_count_lines(char **strs);
void	ft_init_win(t_adata *a);
void	ft_init_map(t_adata *a);
void	ft_init_player(t_adata *a);
void	ft_playerinfo(t_map2d *map, t_player *joe, char **strs);
void	events(t_adata *a);
void	ft_init_img(t_adata *a);
void	ft_init_all(t_adata *a);
void	drawbycomp(int  p_w, int  p_h, t_adata *a);
void	ft_update(t_adata *a);
int		draw_map(t_adata *a);
int		draw_minicircle(t_adata *a);
int		butt_pressed(int keycode, t_adata *a);
int		butt_released(int keycode, t_adata *a);

#endif
