/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 15:01:37 by gleal             #+#    #+#             */
/*   Updated: 2021/03/06 18:22:20 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cub3d(char *cubname)
{
	int fd;
	t_map	map;

		ft_start_tmap(&map);
		fd = open(cubname, O_RDONLY);
		cub_extract(&map, fd);
		if (map.error)
		{
			printf("there was an error while extracting");
			return ;
		}
		if (!ft_parse_cub(map.text, &map))
			return ;
		start_game(&map);
		ft_printcub(map.mapstr);
		ft_freetext(map.mapstr);
}
