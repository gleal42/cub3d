/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 19:21:33 by gleal             #+#    #+#             */
/*   Updated: 2021/03/20 20:26:54 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "../cub3d.h"

# define UP_ARROW 126
# define DOWN_ARROW 125
# define LEFT_ARROW 123
# define RIGHT_ARROW 124

double			calculate_tilesize(t_adata *a);
char			**ft_test_map(void);
int				ft_max_strlen(char **strs);
int				ft_count_lines(char **strs);
void			ft_init_win(t_adata *a);
void			ft_init_map(t_adata *a);
void			ft_init_player(t_adata *a);
void			ft_playerinfo(t_map2d *map, t_player *joe, char **strs);
void			events(t_adata *a);
void			ftinit_img_m(t_adata *a);
void			ftinit_img_3d(t_adata *a);
void			ft_init_all(t_adata *a);
void			drawbycomp(int p_w, int p_h, t_adata *a);
void			ft_update_player(t_adata *a);
int				draw_map(t_adata *a);
int				draw_minicircle(t_adata *a);
int				butt_pressed(int keycode, t_adata *a);
int				butt_released(int keycode, t_adata *a);
void			ftinit_rays(t_adata *a);
int				draw3d(t_adata *a);
int				line(t_line line, t_adata *a);
double			normalrad(double movestep);
int				has_wall(double x, double y, t_adata *a);
int				draw3dline(double ray_angle, t_ray *ray,
				t_adata *a, int col_id);
int				ftinit_texts(t_adata *a);
int				update_sprites(t_adata *a);
int				ft_countsprites(char **strs);
double			distancepoints(double x1, double y1, double x2, double y2);
int				ftinit_img_sps(t_item *item, t_adata *a);
int				add_sprites(t_item *items, char **strs, t_adata *a);
void			ftinit_win(t_adata *a);
void			ftinit_map(t_adata *a);
void			ftinit_player(t_adata *a);
int				ftinit_texts(t_adata *a);
int				ftinit_sprites(t_adata *a);
void			ftinit_img_3d(t_adata *a);
void			ftinit_img_m(t_adata *a);
int				ftinit_img_sps(t_item *item, t_adata *a);
int				destroyimg(t_adata *a, t_img *img);
int				ft_initline(t_adata *a);
int		ftinittext(t_adata *a, t_img *imgt, char *textpath);
int				ft_prepare_3d_line(double ray_angle,
				t_ray *ray, t_adata *a, int col_id);
int				line3d(t_ray *ray, t_adata *a);
int				ft_prepare_sprite_line(t_item *item, t_adata *a,
				int col_id);
int				linesprite(t_item *item,
				t_adata *a, int col_id);
int				bitmap_offset(t_ray *ray, t_adata *a);
int				bitmap_offset_sp(t_item *item, int col_id);
int				has_wall(double x, double y, t_adata *a);
int				is_sprite_stripe(t_item *item, int col_id);
int				ft_prepare_ray_line(t_ray *ray, t_adata *a);
int				vertical_interstep(t_adata *a, t_ray *ray,
				double *nexttouch_verx, double *nexttouch_very);
int				horizontal_interstep(t_adata *a, t_ray *ray,
				double *nexttouch_horx, double *nexttouch_hory);
int				drawsps(t_ray *ray, t_adata *a, int col_id);
int				vertical_cast_facingleft(t_adata *a, t_ray *ray,
				double *nexttouch_verx, double *nexttouch_very);
int				vertical_cast_facingright(t_adata *a, t_ray *ray,
				double *nexttouch_verx, double *nexttouch_very);
int				horizontal_cast_facingup(t_adata *a, t_ray *ray,
				double *nexttouch_horx, double *nexttouch_hory);
int				horizontal_cast_facingdown(t_adata *a, t_ray *ray,
				double *nexttouch_horx, double *nexttouch_hory);
void			horiz_vert_raycomp(t_adata *a, t_ray *ray,
				double *horz_dist, double *vert_dist);

#endif
