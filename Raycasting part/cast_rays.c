/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 16:36:09 by gleal             #+#    #+#             */
/*   Updated: 2021/03/14 20:02:56 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

double	distancepoints(double x1, double y1, double x2, double y2)
{
	return (sqrt(pow((x2 -x1), 2) + pow((y2 - y1), 2)));
}

int		ray_construct(double ray_angle, t_ray *ray, t_adata *a)
{
	ray->wall_hit_horx = 0;
	ray->wall_hit_hory = 0;
	ray->wall_hit_verx = 0;
	ray->wall_hit_very = 0;
	ray->wall_hit_x = 0;
	ray->wall_hit_y = 0;
	ray->found_hor_wall = 0;
	ray->found_ver_wall = 0;
	ray->hit_vertical = 0;

	if (ray_angle > 0 && ray_angle < M_PI)
		ray->facing_down = 1;
	else
		ray->facing_down = 0;
	if (ray_angle > M_PI_2 && ray_angle < (3 * M_PI_2))
		ray->facing_left = 1;
	else
		ray->facing_left = 0;

	//printf("rayangle %f\n", ray_angle);
	//printf("rayfacing down%d\n", ray->facing_down);
	//printf("rayfacing left%d\n", ray->facing_left);
	return (0);
}


int		vertical_cast(double ray_angle, t_ray *ray, t_adata *a)
{
	double	nexttouch_verx;
	double	nexttouch_very;
	double	inter_y;
	double	inter_x;

	inter_x = floor(a->joe.x / a->map.tile_size) * a->map.tile_size;
	if (!ray->facing_left)
		inter_x += a->map.tile_size;
	inter_y = a->joe.y + ((inter_x - a->joe.x) * tan(ray_angle));

	ray->verxstep = a->map.tile_size;
	if (ray->facing_left)
		ray->verxstep *= -1;
	ray->verystep = a->map.tile_size * tan(ray_angle);
	if (!ray->facing_down && ray->verystep > 0)
		ray->verystep *= -1;
	if (ray->facing_down && ray->verystep < 0)
		ray->verystep *= -1;

	nexttouch_verx = inter_x;
	nexttouch_very = inter_y;

/*	if (ray->facing_left)
		nexttouch_verx--;
	else
		nexttouch_verx++;*/

	while (nexttouch_verx >= 0 && nexttouch_verx <= a->map.map_w &&
			nexttouch_very >= 0 && nexttouch_very <= a->map.map_h)
	{
		if (ray->facing_left)
		{
			if (has_wall(nexttouch_verx - 1, nexttouch_very, a))
			{
				ray->found_ver_wall = 1;
				ray->wall_hit_verx = nexttouch_verx;
				ray->wall_hit_very = nexttouch_very;
				break;
			}
			else
			{
				nexttouch_verx += ray->verxstep;
				nexttouch_very += ray->verystep;
			}
		}
		else
		{
			if (has_wall(nexttouch_verx +  1, nexttouch_very, a))
			{
				ray->found_ver_wall = 1;
				ray->wall_hit_verx = nexttouch_verx;
				ray->wall_hit_very = nexttouch_very;
				break;
			}
			else
			{
				nexttouch_verx += ray->verxstep;
				nexttouch_very += ray->verystep;
			}
		}
	}
/*	printf("a->joe.x %f\n", a->joe.x);
	printf("a->joe.y %f\n", a->joe.y);
	printf("intercept_x%f\n", inter_x);
	printf("intercept_y%f\n", inter_y);
	printf("tan(rayangle)%f\n", tan(ray_angle));
	printf("rayangle %f\n", ray_angle);
	printf("rayfacing down%d\n", ray->facing_down);
	printf("rayfacing left%d\n", ray->facing_left);
	printf("x_step %f\n", ray->verxstep);
	printf("y_step %f\n", ray->verystep);
	printf("ray->wall_hit_x %f\n", ray->wall_hit_x);
	printf("ray->wall_hit_y%f\n", ray->wall_hit_y);*/
	return (0);
}

int		horizontal_cast(double ray_angle, t_ray *ray, t_adata *a)
{
	double	nexttouch_horx;
	double	nexttouch_hory;
	double	inter_y;
	double	inter_x;

	inter_y = floor(a->joe.y / a->map.tile_size) * a->map.tile_size;
	if (ray->facing_down)
		inter_y += a->map.tile_size;
	inter_x = a->joe.x + ((inter_y - a->joe.y) / tan(ray_angle));
	ray->horystep = a->map.tile_size;
	if (!ray->facing_down)
		ray->horystep *= -1;
	ray->horxstep = a->map.tile_size / tan(ray_angle);
	if (ray->facing_left && ray->horxstep > 0)
		ray->horxstep *= -1;
	if (!ray->facing_left && ray->horxstep < 0)
		ray->horxstep *= -1;

	nexttouch_horx = inter_x;
	nexttouch_hory = inter_y;

/*	if (!ray->facing_down)
		nexttouch_hory--;
	else
		nexttouch_hory++;*/

	while (nexttouch_horx >= 0 && nexttouch_horx <= a->map.map_w &&
			nexttouch_hory >= 0 && nexttouch_hory <= a->map.map_h)
	{
		if (!ray->facing_down)
		{
			if (has_wall(nexttouch_horx, nexttouch_hory - 1, a))
			{
				ray->found_hor_wall = 1;
				ray->wall_hit_horx = nexttouch_horx;
				ray->wall_hit_hory = nexttouch_hory;
				break;
			}
			else
			{
				nexttouch_horx += ray->horxstep;
				nexttouch_hory += ray->horystep;
			}
		}
		else
		{
			if (has_wall(nexttouch_horx, nexttouch_hory + 1, a))
			{
				ray->found_hor_wall = 1;
				ray->wall_hit_horx = nexttouch_horx;
				ray->wall_hit_hory = nexttouch_hory;
				break;
			}
			else
			{
				nexttouch_horx += ray->horxstep;
				nexttouch_hory += ray->horystep;
			}
		}
	}

//	printf("a->joe.x %f\n", a->joe.x);
//	printf("a->joe.y %f\n", a->joe.y);
//	printf("intercept_x%f\n", inter_x);
//	printf("intercept_y%f\n", inter_y);
//	printf("tan(rayangle)%f\n", tan(ray_angle));
//	printf("rayangle %f\n", ray_angle);
//	printf("rayfacing down%d\n", ray->facing_down);
//	printf("rayfacing left%d\n", ray->facing_left);
//	printf("x_step %f\n", ray->xstep);
//	printf("y_step %f\n", ray->ystep);
//	printf("ray->wall_hit_x %f\n", ray->wall_hit_x);
//	printf("ray->wall_hit_y%f\n", ray->wall_hit_y);
	return (0);
}

int		dda_alg(double ray_angle, t_ray *ray, t_adata *a)
{
	double horz_dist;
		double vert_dist;

	horizontal_cast(ray_angle, ray, a);
		vertical_cast(ray_angle, ray, a);
	if (ray->found_hor_wall)
			horz_dist = (int)distancepoints(a->joe.x, a->joe.y, ray->wall_hit_horx, ray->wall_hit_hory);
		else
			horz_dist = INT_MAX;
		if (ray->found_ver_wall)
			vert_dist = distancepoints(a->joe.x, a->joe.y, ray->wall_hit_verx, ray->wall_hit_very);
		else
			vert_dist = INT_MAX;
		if (horz_dist < vert_dist)
			ray->wall_hit_x = ray->wall_hit_horx;
		else
			ray->wall_hit_x = ray->wall_hit_verx;
		if (horz_dist < vert_dist)
			ray->wall_hit_y = ray->wall_hit_hory;
		else
			ray->wall_hit_y = ray->wall_hit_very;
		if (horz_dist < vert_dist)
			ray->distance = horz_dist;
		else
			ray->distance = vert_dist;
		if (horz_dist < vert_dist)
			ray->hit_vertical = 0;
		else
			ray->hit_vertical = 1;

//	printf("a->joe.x %f\n", a->joe.x);
//	printf("a->joe.y %f\n", a->joe.y);
//	printf("rayangle %f\n", ray_angle);
//	printf("horz_dist %f\n", horz_dist);
//	printf("ray->wall_hit_horx %f\n", ray->wall_hit_horx);
//	printf("ray->wall_hit_hory %f\n", ray->wall_hit_hory);
//	printf("ray->wall_hit_verx %f\n", ray->wall_hit_verx);
//	printf("ray->wall_hit_very %f\n", ray->wall_hit_very);
//	printf("ray->wall_hit_x %f\n", ray->wall_hit_x);
//	printf("ray->wall_hit_y %f\n", ray->wall_hit_y);
//	printf("horz_dist %f\n", horz_dist);
//	printf("vert_dist %f\n", vert_dist);
//	printf("distance %f\n", ray->distance);
//	printf("ray->wall_hit_x %f\n", ray->wall_hit_x);
//	printf("ray->wall_hit_y%f\n", ray->wall_hit_y);
//	printf("hit_vertical%d\n", ray->hit_vertical);
		return (0);
}

int		ft_prepare_ray_line(double ray_angle, t_ray *ray, t_adata *a)
{
	ray->line.start_x = a->joe.x;
	ray->line.start_y = a->joe.y;
	ray->line.end_x = ray->wall_hit_x;
	ray->line.end_y = ray->wall_hit_y;
	ray->line.deltax = ray->line.end_x - ray->line.start_x;
	ray->line.deltay = ray->line.end_y - ray->line.start_y;
	ray->line.pixels = sqrt(pow(ray->line.deltax, 2) + pow(ray->line.deltay, 2));
	ray->line.deltax /= ray->line.pixels;
	ray->line.deltay /= ray->line.pixels;
	ray->line.color = 0xedbc4b;
	return (0);
}

int		cast_all_rays(t_adata *a)
{
	t_ray	ray;
	int col_id;
	double ray_angle;

	col_id = 0;
	ray_angle = normalrad(a->joe.rotangle - (a->ray.fov / 2));

	while (col_id < a->ray.num_rays)
	{
		ray_construct(ray_angle, &ray, a);
		dda_alg(ray_angle, &ray, a);
		ft_prepare_ray_line(ray_angle, &ray, a);
		line(ray.line, a);
		ray_angle = normalrad(ray_angle + (a->ray.fov /a->ray.num_rays)); 
		col_id++;
	}
	return (0);
}
