/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 19:02:02 by gleal             #+#    #+#             */
/*   Updated: 2021/03/11 19:43:23 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

double	normalrad(double movestep)
{
	if (movestep >= (2 * M_PI))
		movestep -= (2 * M_PI);
	if (movestep <= (-2 * M_PI))
		movestep += (2 * M_PI);
	return (movestep);
}

void	ft_update(t_adata *a)
{
	a->joe.rotangle += a->joe.turndir * a->joe.rotatespeed;
	printf("%f\n", a->joe.rotangle);
}
