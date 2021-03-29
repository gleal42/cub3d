/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonuscub.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 18:07:34 by gleal             #+#    #+#             */
/*   Updated: 2021/03/29 17:04:04 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUSCUB_H
# define BONUSCUB_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <unistd.h>
# include <limits.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include "../minilibx/mlx.h"
# include "structs.h"

# define MAX_X_SIZE 2560
# define MAX_Y_SIZE 1440
# define MAP_CHARS "012NSEW"
# define MAP_INSIDE "02NSEW"
# define PLAYER "NSEW"
# define UP_ARROW 126
# define DOWN_ARROW 125
# define LEFT_ARROW 123
# define RIGHT_ARROW 124
# define ESC_KEY 53
# define W_KEY 13
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2
# define SPACE_BAR 49

enum	e_errors
{
	MALLOCERROR,
	MULTIRES,
	BADSCREEN,
	MULTINO,
	BADNO,
	MULTISO,
	BADSO,
	MULTIWE,
	BADWE,
	MULTIEA,
	BADEA,
	MULTISPRITE,
	BADSPRITE,
	MULTIFLOOR,
	BADFLOOR,
	MULTICEIL,
	BADCEIL,
	INVALIDMAP,
	INVALIDCHAR,
	MISSINGPARAMS
};

int				check_resolution(char **text, t_parse *parse,
				int *i, int *count);
int				check_textures(char **text, t_parse *parse, int *i, int *count);
int				check_rgbs(char **text, t_parse *parse, int *i, int *count);
int				check_valid_chars(char **text, int *i);
int				is_map(char *str);
void			*ft_realloctabs(char *str, int tab_nbr, t_parse *parse);
void			*ft_freetext(char **strs);
void			ft_start_tmap(t_parse *parse);
int				ft_countchr(char *str, char c);
void			cub_extract(t_parse *parse, int fd);
int				ft_parse_cub(char **text, t_parse *parse);
int				ft_isspace(char c);
int				ft_error(int errornbr);
int				ft_parsenorthtext(char *str, t_parse *parse);
int				ft_parsesouthtext(char *str, t_parse *parse);
int				ft_parsewesttext(char *str, t_parse *parse);
int				ft_parseeasttext(char *str, t_parse *parse);
int				ft_parsespritetext(char *str, t_parse *parse);
int				checkmultiplayer(char *str, t_parse *parse);
int				check_valid_map(char **strs, t_parse *parse);
int				ft_copy_map(char **map_start, t_parse *parse);
int				start_game(t_adata *a);
int				butt_pressed(int keycode, t_adata *a);
int				butt_released(int keycode, t_adata *a);
int				clicked_cross(int keycode, t_adata *a);
void			ftinit_win(t_adata *a);
void			ftinit_map(t_adata *a);
void			ftinit_player(t_adata *a);
int				ftinit_texts(t_adata *a);
void			ftinit_rays(t_adata *a);
int				ftinit_sprites(t_adata *a);
void			ftinit_img_3d(t_adata *a);
void			ft_update_player(t_adata *a);
int				update_sprites(t_adata *a);
int				draw_ceilingrgb(t_adata *a);
int				create_trgb(int t, int r, int g, int b);
int				draw3d(t_adata *a);
int				draw_map(t_adata *a);
int				destroyimg(t_adata *a, t_img *img);
int				vertical_interstep(t_adata *a, t_ray *ray,
				double *nexttouch_verx, double *nexttouch_very);
int				vertical_cast_facingleft(t_adata *a, t_ray *ray,
				double *nexttouch_verx, double *nexttouch_very);
int				vertical_cast_facingright(t_adata *a, t_ray *ray,
				double *nexttouch_verx, double *nexttouch_very);
int				horizontal_interstep(t_adata *a, t_ray *ray,
				double *nexttouch_horx, double *nexttouch_hory);
int				horizontal_cast_facingup(t_adata *a, t_ray *ray,
				double *nexttouch_horx, double *nexttouch_hory);
int				horizontal_cast_facingdown(t_adata *a, t_ray *ray,
				double *nexttouch_horx, double *nexttouch_hory);
void			horiz_vert_raycomp(t_adata *a, t_ray *ray,
				double *horz_dist, double *vert_dist);
double			normalrad(double movestep);
int				draw3dline(double ray_angle, t_ray *ray,
				t_adata *a, int col_id);
int				drawfloortxt(t_ray *ray, t_adata *a, int col_id);
int				drawsps(t_ray *ray, t_adata *a, int col_id);
int				bitmap_offset(t_ray *ray, t_adata *a);
int				bitmap_offset_sp(t_item *item, int col_id);
int				ft_prepare_3d_line(double ray_angle,
				t_ray *ray, t_adata *a, int col_id);
int				line3d(t_ray *ray, t_adata *a);
int				ft_initline(t_adata *a);
int				line(t_line line, t_adata *a);
int				bitmap_offset_floor(t_adata *a, double *x, double *y);
int				is_sprite_stripe(t_item *item, int col_id);
int				ft_prepare_sprite_line(t_item *item, t_adata *a,
				int col_id);
int				linesprite(t_item *item,
				t_adata *a, int col_id);
void			pickaxe_animation(t_adata *a);
void			ft_init_animation(t_adata *a);
void			clean_sprites(t_adata *a, t_sps *sps);
int				has_wall(double x, double y, t_adata *a);
void			draw_normal_pickaxe(t_adata *a);
int				calc_texx_normal(double small_dist,
				double big_dist, t_adata *a);
int				calc_texy_normal(double small_dist,
				double big_dist, t_adata *a);
void			draw_attack_pickaxe(t_adata *a);
int				calc_texx_attack(double small_dist,
				double big_dist, t_adata *a);
int				calc_texy_attack(double small_dist,
				double big_dist, t_adata *a);

#endif
