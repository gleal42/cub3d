# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gleal <gleal@student.42lisboa.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/09 15:43:58 by gleal             #+#    #+#              #
#    Updated: 2021/03/29 22:17:15 by gleal            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := gcc
FLAGS := -Wall -Wextra -Werror
INCLUDE_DIRS := includes \
				extract_and_parse \
				mandatory_game 
INCLUDES := $(addprefix -I, $(INCLUDE_DIRS))
NAME := cub3D
SRCS_COMMON := ./extract_and_parse/text_extract.c \
	   ./extract_and_parse/ft_parse_cub.c \
	   ./extract_and_parse/ft_parse_resolution.c \
	   ./extract_and_parse/ft_parse_textures.c \
	   ./extract_and_parse/ft_parse_textures2.c \
	   ./extract_and_parse/ft_parse_rgbs.c \
	   ./extract_and_parse/ft_parse_map.c \
	   ./extract_and_parse/ft_parse_map2.c \
	   ./extract_and_parse/ft_parse_utils.c \
	   ./extract_and_parse/ft_parse_utils2.c \
	   ./mandatory_game/ft_init.c \
	   ./mandatory_game/ft_init2.c \
	   ./mandatory_game/ft_initdestroyimg.c \
	   ./mandatory_game/update_sprites.c \
	   ./mandatory_game/cast_rays_horizontal.c \
	   ./mandatory_game/cast_rays_vertical.c \
	   ./mandatory_game/horiz_vert_raycomp.c \
	   ./mandatory_game/start_game_utils.c \
	   ./mandatory_game/start_game_utils2.c \
	   ./mandatory_game/start_game_utils3.c \
	   ./mandatory_game/color_utils.c \
	   ./other_utils/free_utils.c \
	   ./other_utils/ft_error.c
OBJS_COMMON := $(SRCS_COMMON:.c=.o)
SRCS_MANDATORY := cub3d.c \
	./mandatory_game/start_game.c \
	./mandatory_game/events.c \
	./mandatory_game/update.c \
	./mandatory_game/cast_rays.c \
	./mandatory_game/ft_prepare_lines.c \
	./mandatory_game/lines.c \
	./mandatory_game/draw.c \
	./mandatory_game/draw2.c \
	./mandatory_game/bitmap_offsets.c \
	./mandatory_game/bmp_screenshot.c
OBJS_MANDATORY := $(SRCS_MANDATORY:.c=.o)
SRCS_BONUS := ./bonus_game/cub3d_bonus.c \
	./bonus_game/start_game_bonus.c \
	./bonus_game/events_bonus.c \
	./bonus_game/update_bonus.c \
	./bonus_game/cast_rays_bonus.c \
	./bonus_game/ft_prepare_lines_bonus.c \
	./bonus_game/lines_bonus.c \
	./bonus_game/draw_bonus.c \
	./bonus_game/draw2_bonus.c \
	./bonus_game/bitmap_offsets_bonus.c \
	./bonus_game/ft_init_anim_bonus.c \
	./bonus_game/utils_normal_pickaxe_bonus.c \
	./bonus_game/utils_attack_pickaxe_bonus.c
OBJS_BONUS := $(SRCS_BONUS:.c=.o)

all: libft minilibx $(NAME) 

libft:
	make -C libft/

minilibx:
	make -C minilibx/

%.o : %.c
	$(CC) $(FLAGS) -c $^ -o $@ $(INCLUDES)

$(NAME) : $(OBJS_COMMON) $(OBJS_MANDATORY) 
	$(CC) $(FLAGS) $^ -Lminilibx/ -lmlx -framework OpenGL -framework AppKit -Llibft -lft -o $@ $(INCLUDES)

bonus: libft minilibx bonus_comp

bonus_comp: $(OBJS_COMMON) $(OBJS_BONUS)
	$(CC) $(FLAGS) $^ -Lminilibx/ -lmlx -framework OpenGL -framework AppKit -Llibft -lft -o bonus $(INCLUDES)

clean:
	rm -f $(OBJS_COMMON)
	rm -f $(OBJS_MANDATORY)
	rm -f $(OBJS_BONUS)
	$(MAKE) -C libft/ clean
	$(MAKE) -C minilibx/ clean

fclean: clean
		rm -f $(NAME)
		rm -f bonus
	$(MAKE) -C libft/ fclean

re: fclean all

.PHONY: libft minilibx all bonus clean fclean re
