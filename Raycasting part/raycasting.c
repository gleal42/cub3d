/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:20:19 by gleal             #+#    #+#             */
/*   Updated: 2021/03/10 21:11:44 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	render_mini(t_adata *a, void (*draw)(double, double, t_adata *a))
{
	int	pixel_w;
	int	pixel_h;

	pixel_h = 0;
	while (pixel_h < a->map.map_h)
	{
		pixel_w = 0;
		while (pixel_w < a->map.map_w)
		{
			draw(pixel_w, pixel_h, a);
			pixel_w++;
		}
		pixel_h++;
	}
}

int     main(void)
{
	t_adata a;

	ft_init_all(&a);
	events(&a);
	mlx_loop_hook(a.win.mlx, render_next_frame, &a);
	mlx_loop(a.win.mlx);
	return (0);
}
