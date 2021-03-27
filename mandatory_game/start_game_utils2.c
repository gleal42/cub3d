/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 16:42:55 by gleal             #+#    #+#             */
/*   Updated: 2021/03/27 20:05:22 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./start_game.h"

int		find_text_wallhit(double ray_angle, t_ray *ray, t_adata *a)
{
	if (ray->hit_vertical)
	{
		if (normalrad(ray_angle) > M_PI_2 &&
		normalrad(ray_angle) < (3 * M_PI_2))
			ray->text_wallhit = a->wetext;
		else
			ray->text_wallhit = a->eatext;
	}
	else
	{
		if (normalrad(ray_angle) > M_PI &&
		normalrad(ray_angle) < 2 * M_PI)
			ray->text_wallhit = a->notext;
		else
			ray->text_wallhit = a->sotext;
	}
	return (0);
}

int		has_wall(double x, double y, t_adata *a)
{
	int		mapgridx;
	int		mapgridy;

	if ((int)x < 0 || (int)x > a->map.map_w ||
	(int)y < 0 || (int)y > a->map.map_h)
		return (1);
	mapgridx = (int)x / a->map.tile_size;
	mapgridy = (int)y / a->map.tile_size;
	if (mapgridx >= (int)ft_strlen(a->map.maptxt[mapgridy]))
		return (1);
	if (a->map.maptxt[(int)mapgridy][(int)mapgridx] == '1')
		return (1);
	return (0);
}

double	normalrad(double movestep)
{
	if (movestep >= (2 * M_PI))
		movestep -= (2 * M_PI);
	if (movestep < (0))
		movestep += (2 * M_PI);
	return (movestep);
}

double	distancepoints(double x1, double y1, double x2, double y2)
{
	return (sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2)));
}

int		ftinittext(t_adata *a, t_img *imgt, char *textpath)
{
	imgt->ptr = mlx_xpm_file_to_image(a->win.mlx,
	textpath, &imgt->width, &imgt->height);
	imgt->addr = (int *)mlx_get_data_addr(imgt->ptr,
	&imgt->pixel_bits, &imgt->line_bytes,
	&imgt->endian);
	return (0);
}
