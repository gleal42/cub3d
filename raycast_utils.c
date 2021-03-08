/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 13:21:39 by gleal             #+#    #+#             */
/*   Updated: 2021/03/08 16:52:23 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "raycasting.h"

int		ft_max_strlen(char **strs)
{
	int		i;
	int		j;
	int		max_len;

	i = 0;
	j = 0;
	max_len = 0;
	while (strs[i])
	{
		j = 0;
		while (strs[i][j])
			j++;
		if (j > max_len)
			max_len = j;
		i++;
	}
	return (max_len);
}	

int		ft_count_lines(char **strs)
{
	int i;

	i = 0;
	while (strs[i])
		i++;
	return (i);
}

char	**ft_test_map(void)
{
	char	**official;
	int		i;
	char 	*temp[] = {
"        1111111111111111111111111",
"        1000000000110000000000001",
"        1011000001110000002000001",
"        1001000000000000000000001",
"111111111011000001110000000000001",
"100000000011000001110111111111111",
"11110111111111011100000010001",
"11110111111111011101010010001",
"11000000110101011100000010001",
"10002000000000001100000010001",
"10000000000000001101010010001",
"11000001110101011111011110N0111",
"11110111 1110101 101111010001",
"11111111 1111111 111111111111",
0
	};

	i = 0;
	ft_count_lines(temp);
	official = malloc(sizeof(char*) * (ft_count_lines(temp) + 1));
	while (temp[i])
	{
		official[i] = ft_strdup(temp[i]);
		i++;
	}
	official[i] = 0;
	return (official);
}
