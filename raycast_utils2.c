/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 15:31:03 by gleal             #+#    #+#             */
/*   Updated: 2021/03/07 20:35:38 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "raycasting.h"

# define WIN_WIDTH 800
# define WIN_HEIGHT 600

void	ft_put_map(t_datat *data)
{
	int	count_w;
	int	count_h;

	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->window_width, data->window_height, "Wolfenstein3D");
	data->map2d = mlx_new_image(data->mlx, 500, 500);
	data->addr = (int *)mlx_get_data_addr(data->map2d, &data->pixel_bits, &data->line_bytes, &data->endian);
	data->line_bytes /= 4;
	count_h = 0;
	while (count_h < 500)
	{
		count_w = 0;
		while (count_w < 500)
		{
			 data->addr[count_h * 500 + count_w] = 0x50FFFF;
			 count_w++;
		}
		count_h++;
	}
		mlx_put_image_to_window(data->mlx, data->win, data->map2d, 500, 500);
	    mlx_loop(data->mlx);
}
