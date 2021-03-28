/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 15:13:07 by gleal             #+#    #+#             */
/*   Updated: 2021/03/28 18:20:29 by gleal            ###   ########.fr       */
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
# include <math.h>
# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include "../minilibx/mlx.h"
# include "structs.h"
# include "ft_parse.h"
# include "start_game.h"

# define MAX_X_SIZE 2560
# define MAX_Y_SIZE 1440
# define MAP_CHARS "012NSEW"
# define MAP_INSIDE "02NSEW"
# define PLAYER "NSEW"

#endif
