/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 19:21:33 by gleal             #+#    #+#             */
/*   Updated: 2021/03/08 16:50:47 by gleal            ###   ########.fr       */
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
	char	**maptxt;
	int		map_w;
	int		map_h;
	double	map_rows;
	double	map_cols;
	void 	*map2d;
	int		*addr;
	int		tile_size;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
}				t_map2d;

typedef struct	s_player
{
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

#endif
