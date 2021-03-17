/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_texts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 15:35:28 by gleal             #+#    #+#             */
/*   Updated: 2021/03/17 21:07:56 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

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
	inittest_img_m(mlx, win);
	mlx_loop(mlx);
}
