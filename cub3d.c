/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 15:01:37 by gleal             #+#    #+#             */
/*   Updated: 2021/03/28 21:51:11 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	else if (argc == 3)
	{
		if (!(ft_strncmp("--save", argv[2], ft_strlen(argv[2]))) &&
				ft_strlen(argv[2]) == 6)
			screenshot(argv[1]);
		else
			printf("WRONG");
	}
	else
		printf("WRONG");
}
