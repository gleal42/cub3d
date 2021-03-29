/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 15:01:37 by gleal             #+#    #+#             */
/*   Updated: 2021/03/29 20:11:25 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		cub3d(char *cubname)
{
	int			fd;
	t_adata		a;

	ft_start_tmap(&a.parse);
	fd = open(cubname, O_RDONLY);
	if (fd <= 0)
		return (ft_error(INVALID_FILE));
	cub_extract(&a.parse, fd);
	if (a.parse.error)
	{
		printf("there was an error while extracting");
		return (0);
	}
	if (!ft_parse_cub(a.parse.text, &a.parse))
	{
		ft_freetext(a.parse.text);
		free_all_texts(&a.parse);
		return (0);
	}
	start_game(&a);
	return (1);
}

int		main(int argc, char **argv)
{
	if (argc < 2)
		printf("You forgot the cub file name");
	else if (argc == 2)
	{
		if (!is_cubfile(argv[1]))
			return (ft_error(NOT_CUB_ERROR));
		cub3d(argv[1]);
	}
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
