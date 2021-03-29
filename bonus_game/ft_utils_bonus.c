/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 16:06:15 by gleal             #+#    #+#             */
/*   Updated: 2021/03/29 16:25:14 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonuscub.h"

int		calc_texy(double small_dist, double big_dist, t_adata *a)
{
	int result;

	result = (int)((small_dist/big_dist) * (a->wetext.imgt.height - 1));
	return (result);
}

int		calc_texx(double small_dist, double big_dist, t_adata *a)
{
	int result;

	result = (int)((small_dist / big_dist) * (a->wetext.imgt.width - 1));
	return (result);
}

void	draw_normal_pickaxe(t_adata *a)
{

}
