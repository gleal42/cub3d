/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_texts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 15:35:28 by gleal             #+#    #+#             */
/*   Updated: 2021/03/18 16:31:09 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

int		create_trgb(int t, int r, int g, int b)
{
	return(t << 24 | r << 16 | g << 8 | b);
}

void	blue_rect(void	*mlx, void	*win)
{
	void 	*ptr;
	int		*addr;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	int		width;
	int		height;

	ptr = mlx_new_image (mlx, 1920, 1080);
	addr = (int *)mlx_get_data_addr(ptr, &pixel_bits, &line_bytes, &endian);
	line_bytes /= 4;

	int color = create_trgb(0, 193, 204, 140);

for(int y = 0; y < 360; ++y)
for(int x = 0; x < 640; ++x)
{
    addr[(y * line_bytes) + x] = color;
}
	mlx_put_image_to_window(mlx, win, ptr, 0, 0);
}

void	inittest_img_m(void *mlx, void *win)
{
	void 	*ptr;
	int		*addr;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	int		width;
	int		height;

	ptr = mlx_xpm_file_to_image(mlx, "../textures/barrel.xpm", &width, &height);
	/*addr = (int *)mlx_get_data_addr(ptr, &pixel_bits, &line_bytes, &endian);*/
	mlx_put_image_to_window(mlx, win, ptr, 0, 0);
}

int		main(void)
{
	void	*mlx;
	void	*win;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 64, 64, "my_mlx");
	blue_rect(mlx, win);
	mlx_loop(mlx);
}
