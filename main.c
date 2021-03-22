/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 15:01:55 by gleal             #+#    #+#             */
/*   Updated: 2021/03/22 20:04:40 by gleal            ###   ########.fr       */
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
