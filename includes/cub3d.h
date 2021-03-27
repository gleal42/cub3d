/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 15:13:07 by gleal             #+#    #+#             */
/*   Updated: 2021/03/27 22:20:05 by gleal            ###   ########.fr       */
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
# include "libft.h"
# include "get_next_line.h"
# include "structs.h"
# include "../extract_and_parse/ft_parse.h"
# include "../mandatory_game/start_game.h"
# include "../minilibx/mlx.h"

# define MAX_X_SIZE 2560
# define MAX_Y_SIZE 1440
# define MAP_CHARS "012NSEW"
# define MAP_INSIDE "02NSEW"
# define PLAYER "NSEW"

#endif
