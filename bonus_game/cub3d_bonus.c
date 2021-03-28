/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 17:40:54 by gleal             #+#    #+#             */
/*   Updated: 2021/03/28 18:17:03 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonuscub.h"

void	cub3d(char *cubname)
{
	int			fd;
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

int		main(int argc, char **argv)
{
	if (argc < 2)
		printf("You forgot the cub file name");
	else if (argc == 2)
		cub3d(argv[1]);
	else
		printf("WRONG");
}
