# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kakumar <kakumar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/19 09:35:57 by kakumar           #+#    #+#              #
#    Updated: 2023/02/04 16:52:50 by kakumar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror

MINIFLAGS = /usr/local/lib/libmlx.a -I /usr/local/include/mlx.h -framework OpenGL -framework Appkit

SRC = draw_utils.c draw.c image.c keyboard.c map.c rotations.c

OBJECTFILES = draw_utils.o draw.o image.o keyboard.o map.o rotations.o

NAME = fdf.a

LIBFT = libft/

all: $(NAME)

$(NAME):
	cd $(LIBFT) && $(MAKE)
	cp $(LIBFT)libft.a $(NAME)
	cc -c $(SRC) $(FLAGS)
	ar rcs $(NAME) $(OBJECTFILES)
	cc $(FLAGS) $(NAME) main.c $(MINIFLAGS) -o fdf

clean:
	rm -f $(OBJECTFILES)
	cd $(LIBFT) && $(MAKE) clean

fclean: clean
	rm -f $(NAME)
	rm -f fdf
	cd $(LIBFT) && $(MAKE) fclean

re: fclean all

.PHONY: all clean fclean re