/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 20:16:24 by gleal             #+#    #+#             */
/*   Updated: 2021/03/17 15:29:32 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

int		bitmap_offset(t_ray *ray, t_adata *a)
{
	double	ray_x;
	double	ray_y;
	double	remainder;
	double	offset;

	ray_x = ray->wall_hit_x/a->map.tile_size;
	ray_y = ray->wall_hit_y/a->map.tile_size;

	if (ray->hit_vertical)
	{
		remainder = ray_y - floor(ray_y);
		offset = a->sotext.imgt.width * remainder;
	}
	else
	{
		remainder = ray_x - floor(ray_x);
		offset =a->sotext.imgt.width * remainder;
	}
	return (offset);
}

int		line3d(double ray_angle, t_ray *ray, t_adata *a, int col_id)
{
	double remain_pixels;
	double pixelx;
	double pixely;
	double texx;
	double texy;

	pixelx = a->line_3d.start_x;
	pixely = a->line_3d.start_y;
	texy = 0;
	texx = bitmap_offset(ray, a);
	remain_pixels = a->line_3d.pixels;
	//printf("texx %f\n", texx);
	while (remain_pixels >= 0)
	{
		a->img_3d.addr[((int)pixely * (int)a->win.win_w + (int)pixelx)] =
			a->sotext.imgt.addr[(int)texy * (int)a->sotext.imgt.width + (int)texx];
		pixelx += a->line_3d.deltax;
		pixely += a->line_3d.deltay;
		texy = ((pixely - a->line_3d.start_y) * a->sotext.imgt.width)/ a->line_3d.pixels;
		//printf("texy %f\n", texy);
		--remain_pixels;
	}
	return (0);
}

int		ft_prepare_3d_line(double ray_angle, t_ray *ray, t_adata *a, int col_id)
{
	double		line_height;
	double		adjusted_pos;
	double		nofish_ang;
	double		nofish_dist;

	nofish_dist = (ray->distance/a->map.tile_size)* cos(ray_angle - a->joe.rotangle);
	line_height = a->ray.distprojplane/nofish_dist;
	a->line_3d.start_x = col_id;
	a->line_3d.start_y = (a->win.win_h/2) - (line_height/2);
	if(a->line_3d.start_y < 0)
		a->line_3d.start_y= 0;
	a->line_3d.end_x = col_id;
	a->line_3d.end_y = (a->win.win_h/2) + (line_height/2);
	if(a->line_3d.end_y >= a->win.win_h)
		a->line_3d.end_y = a->win.win_h - 1.0;
	a->line_3d.deltax = a->line_3d.end_x - a->line_3d.start_x;
	a->line_3d.deltay = a->line_3d.end_y - a->line_3d.start_y;
	a->line_3d.pixels = sqrt(pow(a->line_3d.deltax, 2) + pow(a->line_3d.deltay, 2));
	a->line_3d.deltax /= a->line_3d.pixels;
	a->line_3d.deltay /= a->line_3d.pixels;
	
//printf("%d\n", a->notext.imgt.width);
/*	a->line_3d.color = 0x77b3cf;*/

//	printf("nofish_ang%f\n", nofish_ang);
//	printf("nofish_dist%f\n", nofish_dist);
//	printf("ray->distance%f\n", ray->distance);
//	printf("line_height%f\n", line_height);
//	printf("adjusted_pos%f\n", adjusted_pos);
//	printf("a->line_3d.start_x%f\n", a->line_3d.start_x);
//	printf("a->line_3d.start_y%f\n", a->line_3d.start_y);
//	printf("a->line_3d.end_x%f\n", a->line_3d.end_x);
//	printf("a->line_3d.end_y%f\n", a->line_3d.end_y);
//	printf("a->line_3d.deltax%f\n", a->line_3d.deltax);
//	printf("a->line_3d.deltay%f\n", a->line_3d.deltay);

	return (0);
}

int		draw3d(double ray_angle, t_ray *ray, t_adata *a, int col_id)
{
	ft_prepare_3d_line(ray_angle, ray, a, col_id);
	line3d(ray_angle, ray, a, col_id);
	return (0);
}
