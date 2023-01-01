# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kakumar <kakumar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/19 09:35:57 by kakumar           #+#    #+#              #
#    Updated: 2022/12/19 12:58:01 by kakumar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror

SRC = 

OBJECTFILES = 

NAME = libft.a

LIBFT = libft/

all: $(NAME)

$(NAME):
	cd $(LIBFT) && $(MAKE)
	cp $(LIBFT)libft.a $(NAME)
	cc -c $(SRC) $(FLAGS)
	ar rcs $(NAME) $(OBJECTFILES)

clean:
	rm -f $(OBJECTFILES) $(OBJECTFILES_BONUS)
	cd $(LIBFT) && $(MAKE) clean

fclean: clean
	rm -f $(NAME)
	cd $(LIBFT) && $(MAKE) fclean

re: fclean all

.PHONY: all clean fclean re