/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 15:01:37 by gleal             #+#    #+#             */
/*   Updated: 2021/03/21 22:14:57 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void	screenshot(char *cubname)
{
	(void)cubname;
	return ;
	/*ft_start_tmap(&a.parse);
	fd = open(cubname, O_RDONLY);
	cub_extract(&a.parse, fd);
	if (a.parse.error)
	{
		printf("there was an error while extracting");
		return ;
	}
	if (!ft_parse_cub(a.parse.text, &a.parse))
		return ;
	start_game(&a);*/
}

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
