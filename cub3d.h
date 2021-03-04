/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 15:13:07 by gleal             #+#    #+#             */
/*   Updated: 2021/03/03 21:04:30 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <unistd.h>
# include <limits.h>
# include <unistd.h>
# include <fcntl.h>
#include <mlx.h>

# include "./libft_cub3d/libft.h"
# include "./libft_cub3d/get_next_line.h"

typedef struct	s_map
{
	int		lnbr;
	char	**text;
	int		error;
	int		rx;
	int		ry;

}				t_map;

void	*ft_freetext(char **strs);
void	*ft_realloctabs(char *str, int tab_nbr, t_map *map);
void	ft_start_tmap(t_map *map);
void	ft_new_line(t_map *map);
int		ft_countchr(char *str, char c);
void	cub_extract(t_map *map, int fd);
void	cub3d(char *cubname);
void	ft_printcub(char **cub);
void	ft_parse_cub(char **text, t_map *map);

#endif
