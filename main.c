/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 15:01:55 by gleal             #+#    #+#             */
/*   Updated: 2021/03/21 22:15:28 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_printcub(char **cub)
{
	while (*cub)
	{
		printf("%s\n", *cub);
		cub++;
	}
}

int		main(int argc, char **argv)
{
	if (argc < 2)
		printf("You forgot the cub file name");
	if (argc == 2)
		cub3d(argv[1]);
	/*if (argc == 3)
	{
		if (ft_strcmp("--save", argv[2]) == 0)
			screenshot(argv[1]);
	}*/
}
