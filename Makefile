# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gleal <gleal@student.42lisboa.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/09 15:43:58 by gleal             #+#    #+#              #
#    Updated: 2021/03/27 22:19:55 by gleal            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror -g -fsanitize=address -fno-omit-frame-pointer
INCLUDES = -Iinclude -Ilibft
NAME = cub3D
SRCS_MANDATORY = cub3d.c \
	   ./extract_and_parse/text_extract.c \
	   ./extract_and_parse/ft_parse_cub.c \
	   ./extract_and_parse/ft_parse_resolution.c \
	   ./extract_and_parse/ft_parse_textures.c \
	   ./extract_and_parse/ft_parse_textures2.c \
	   ./extract_and_parse/ft_parse_rgbs.c \
	   ./extract_and_parse/ft_parse_map.c \
	   ./extract_and_parse/ft_parse_map2.c \
	   ./extract_and_parse/ft_parse_utils.c \
	   ./mandatory_game/start_game.c \
	   ./mandatory_game/ft_init.c \
	   ./mandatory_game/ft_init2.c \
	   ./mandatory_game/ft_initdestroyimg.c \
	   ./mandatory_game/events.c \
	   ./mandatory_game/update.c \
	   ./mandatory_game/update_sprites.c \
	   ./mandatory_game/cast_rays.c \
	   ./mandatory_game/cast_rays_horizontal.c \
	   ./mandatory_game/cast_rays_vertical.c \
	   ./mandatory_game/horiz_vert_raycomp.c \
	   ./mandatory_game/draw.c \
	   ./mandatory_game/draw2.c \
	   ./mandatory_game/ft_prepare_lines.c \
	   ./mandatory_game/lines.c \
	   ./mandatory_game/bitmap_offsets.c \
	   ./mandatory_game/start_game_utils.c \
	   ./mandatory_game/start_game_utils2.c \
	   ./mandatory_game/start_game_utils3.c \
	   ./mandatory_game/color_utils.c \
	   ./mandatory_game/bmp_screenshot.c \
	   ./other_utils/free_utils.c \
	   ./other_utils/ft_error.c

OBJS_MANDATORY = $(SRCS_MANDATORY:.c=.o)

all: $(NAME)

libft:
	make -C libft/

minilibx:
	make -C minilibx/

%.o : %.c
	$(CC) $(FLAGS) -c $^ -o $@ $(INCLUDES)

$(NAME) : $(OBJS_MANDATORY)
	$(CC) $(FLAGS) $^ -Lminilibx/ -lmlx -framework OpenGL -framework AppKit -Llibft -lft -o $@ $(INCLUDES)

clean:
	rm -f $(OBJS_MANDATORY)
	$(MAKE) -C libft/ clean
	$(MAKE) -C minilibx/ clean

fclean: clean
		rm -f $(NAME)
	$(MAKE) -C libft/ fclean

re: fclean all

.PHONY: libft minilibx all clean fclean re
