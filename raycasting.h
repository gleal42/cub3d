/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 19:21:33 by gleal             #+#    #+#             */
/*   Updated: 2021/03/08 21:57:43 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

typedef struct	s_win
{
	void	*mlx;
	double	win_w;
	double	win_h;
	void	*win;
}				t_win;

typedef struct	s_map2d
{
	void 	*map2d;
	int		*addr;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	double	tile_size;
	char	**maptxt;
	double		map_w;
	double	map_h;
	double	map_rows;
	double	map_cols;
}				t_map2d;

typedef struct	s_player
{
	void 	*joe;
	int		*addr;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	double	x;
	double	y;
	double	radius;
	double	turndir;
	double	walkdir;
	double	rotangle;
	double	movespeed;
	double	rotatespeed;
}				t_player;

typedef struct	s_adata
{
	t_win		win;
	t_map2d		map;;
	t_player	joe;
}				t_adata;

char	**ft_test_map(void);
int		ft_max_strlen(char **strs);
int		ft_count_lines(char **strs);
void	ft_init_win(t_adata *a);
void	ft_init_map(t_adata *a);
void	ft_init_player(t_adata *a);
void	ft_playerinfo(t_map2d *map, t_player *joe, char **strs);

#endif
