/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_normal_pickaxe.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 17:06:06 by gleal             #+#    #+#             */
/*   Updated: 2021/03/29 17:08:26 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonuscub.h"

int		calc_texy_normal(double small_dist, double big_dist, t_adata *a)
{
	int result;

	result = (int)((small_dist / big_dist) * (a->wetext.imgt.height - 1));
	return (result);
}

int		calc_texx_normal(double small_dist, double big_dist, t_adata *a)
{
	int result;

	result = (int)((small_dist / big_dist) * (a->wetext.imgt.width - 1));
	return (result);
}

void	draw_normal_pickaxe(t_adata *a)
{
	double		p_w;
	double		p_h;
	double		start_w;
	double		start_h;
	int			m_y;
	int			m_x;

	start_w = ceil((double)(a->win.win_w / 2));
	start_h = ceil((double)(a->win.win_h / 2));
	p_h = start_h;
	while ((int)p_h < a->win.win_h)
	{
		p_w = start_w;
		while ((int)p_w < a->win.win_w)
		{
			m_y = calc_texy_normal(p_h - start_h, a->win.win_h - 1 - start_h, a);
			m_x = calc_texx_normal(p_w - start_w, a->win.win_w - 1 - start_w, a);
			if (a->wetext.imgt.addr [m_y * a->wetext.imgt.width + m_x])
			{
				a->img_3d.addr[(int)(int)p_h * (int)a->win.win_w + (int)p_w] =
				a->wetext.imgt.addr [m_y * a->wetext.imgt.width + m_x];
			}
			p_w++;
		}
		p_h++;
	}
}
