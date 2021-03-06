# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gleal <gleal@student.42lisboa.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/09 15:43:58 by gleal             #+#    #+#              #
#    Updated: 2021/03/06 16:13:27 by gleal            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror -g -fsanitize=address -fno-omit-frame-pointer
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
	   start_game.c \

OBJS = $(SRCS:.c=.o)

all: libft minilibx $(NAME)

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
