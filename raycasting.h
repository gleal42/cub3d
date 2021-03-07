/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 19:21:33 by gleal             #+#    #+#             */
/*   Updated: 2021/03/07 19:56:20 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

typedef struct	s_testmap
{
	char	**map;
	double	map_num_rows;
	double	map_num_cols;
	double	tile_size;
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
	double	time;
	double	oldtime;
	void 	*map2d;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	char	*buffer;
}				t_testmap;

typedef struct	s_player
{
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
	double	time;
	double	oldtime;
}				t_player;

typedef struct	s_datat
{
	void	*mlx;
	double	window_width;
	double	window_height;
	void	*win;
	void 	*map2d;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	int		*addr;
	t_testmap	*mapinfo;
	t_player	*player;
}				t_datat;

char	**ft_test_map(void);
void	ft_allocinfo(t_datat **data);
void	screenstart(t_datat *data);
void	ft_put_map(t_datat *data);

#endif
