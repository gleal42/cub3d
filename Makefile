# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gleal <gleal@student.42lisboa.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/09 15:43:58 by gleal             #+#    #+#              #
#    Updated: 2021/03/19 19:30:29 by gleal            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror -g -fsanitize=address -fno-omit-frame-pointer -Iraycasting_part
NAME = cub3D
SRCS = ft_map_utils.c \
	   text_extract.c \
	   cub3d.c \
	   main.c \
	   ft_parse_cub.c \
	   ft_parse_tools.c \
	   ft_parse_tools2.c \
	   ft_parse_tools3.c \
	   ft_parse_tools4.c \
	   ft_map_utils2.c \
	   ./raycasting_part/raycasting.c \
	   ./raycasting_part/events.c \
	   ./raycasting_part/ft_init.c \
	   ./raycasting_part/ft_init2.c \
	   ./raycasting_part/ft_init_texts.c \
	   ./raycasting_part/ft_initdestroyimg.c \
	   ./raycasting_part/update.c \
	   ./raycasting_part/update_sprites.c \
	   ./raycasting_part/draw.c \
	   ./raycasting_part/draw2.c \
	   ./raycasting_part/ft_prepare_lines.c \
	   ./raycasting_part/lines.c \
	   ./raycasting_part/raycast_utils.c \
	   ./raycasting_part/raycast_utils2.c \
	   ./raycasting_part/raycast_utils3.c \
	   ./raycasting_part/cast_rays.c \
	   ./raycasting_part/cast_rays_horizontal.c \
	   ./raycasting_part/cast_rays_vertical.c \
	   ./raycasting_part/horiz_vert_raycomp.c \
	   ./raycasting_part/bitmap_offsets.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

libft:
	make -C libft/

minilibx:
	make -C minilibx/

%.o : %.c
	$(CC) $(FLAGS) -c $^ -o $@

$(NAME) : $(OBJS)
	$(CC) $(FLAGS) $^ -Lminilibx/ -lmlx -framework OpenGL -framework AppKit -Llibft -lft -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C libft/ clean
	$(MAKE) -C minilibx/ clean

fclean: clean
		rm -f $(NAME)
	$(MAKE) -C libft/ fclean

re: fclean all

.PHONY: libft minilibx all clean fclean re
