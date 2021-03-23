/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 19:46:44 by gleal             #+#    #+#             */
/*   Updated: 2021/03/23 19:03:39 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef	struct	s_bmp
{
	int				filesize;
	char			*img;
	unsigned char	fileheader[14];
	unsigned char	infoheader[40];
	unsigned char	pad[3];
	int				color;
	int				fd;
}				t_bmp;

typedef struct	s_parse
{
	int		lnbr;
	char	**text;
	int		error;
	int		rx;
	int		ry;
	char	*no_text;
	char	*so_text;
	char	*we_text;
	char	*ea_text;
	char	*sprite_text;
	int		rfloor;
	int		gfloor;
	int		bfloor;
	int		rceil;
	int		gceil;
	int		bceil;
	int		map_size;
	char	player_or;
	char	**mapstr;
}				t_parse;

typedef struct	s_win
{
	void	*mlx;
	double	win_w;
	double	win_h;
	void	*win;
}				t_win;

typedef struct	s_img
{
	void	*ptr;
	int		*addr;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	int		width;
	int		height;
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
	double		x;
	double		y;
	double		radius;
	char		walkdir;
	int			turndir;
	double		rotangle;
	double		movespeed;
	double		rotatespeed;
}				t_player;

typedef struct	s_line
{
	double		start_x;
	double		start_y;
	double		end_x;
	double		end_y;
	int			color;
	double		deltax;
	double		deltay;
	double		pixels;
}				t_line;

typedef struct	s_text
{
	char		*text_name;
	t_img		imgt;
}				t_text;

typedef struct	s_ray
{
	double		fov;
	double		fovref_min;
	double		fovref_max;
	double		wall_strip_w;
	int			num_rays;
	double		distprojplane;
	double		ray_angle;
	int			facing_down;
	int			facing_left;
	double		horxstep;
	double		horystep;
	double		verxstep;
	double		verystep;
	double		wall_hit_horx;
	double		wall_hit_hory;
	double		wall_hit_verx;
	double		wall_hit_very;
	double		wall_hit_x;
	double		wall_hit_y;
	int			found_hor_wall;
	int			found_ver_wall;
	double		distance;
	int			hit_vertical;
	t_text		text_wallhit;
	t_line		line;
}				t_ray;

typedef struct	s_item
{
	double		x;
	double		y;
	double		angle;
	double		distance;
	double		sprite_h;
	double		sprite_w;
	double		ystart;
	double		yend;
	double		xstart;
	double		xend;
	int			is_visible;
	t_img		imgsp;
}				t_item;

typedef struct	s_sps
{
	int			number;
	t_item		*items;
}				t_sps;

typedef struct	s_adata
{
	t_parse		parse;
	t_win		win;
	t_map2d		map;
	t_player	joe;
	t_img		img_m;
	t_img		img_3d;
	t_line		line_3d;
	t_line		line;
	t_ray		ray;
	t_text		notext;
	t_text		sotext;
	t_text		eatext;
	t_text		wetext;
	t_sps		sps;
	t_line		line_sp;
}				t_adata;

#endif
