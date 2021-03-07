/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testinglib.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 19:23:01 by gleal             #+#    #+#             */
/*   Updated: 2021/03/07 19:25:17 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "raycasting.h"

/*ft_printcub(data->mapinfo->map);

void	ft_printcub(char **cub)
{
	while (*cub)
	{
		printf("%s\n", *cub);
		cub++;
	}
}*/

void	ft_init_ray()
{

}

int     main(void)
{
	t_datat *data;

	ft_allocinfo(&data);
	screenstart(data);
	ft_put_map(data);
	return (0);
}
