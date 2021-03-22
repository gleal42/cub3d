/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 15:01:37 by gleal             #+#    #+#             */
/*   Updated: 2021/03/22 16:35:45 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cub3d(char *cubname)
{
	int fd;
	t_adata		a;

		ft_start_tmap(&a.parse);
		fd = open(cubname, O_RDONLY);
		cub_extract(&a.parse, fd);
		if (a.parse.error)
		{
			printf("there was an error while extracting");
			return ;
		}
		if (!ft_parse_cub(a.parse.text, &a.parse))
			return ;
		start_game(&a);
}
