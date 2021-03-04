/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 15:01:55 by gleal             #+#    #+#             */
/*   Updated: 2021/03/03 20:07:26 by gleal            ###   ########.fr       */
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
}
