# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmeerber <mmeerber@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/12 19:15:48 by mmeerber          #+#    #+#              #
#    Updated: 2023/12/01 16:14:00 by mmeerber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = ./libft_and_more.a
SRCS = $(wildcard libft/*.c) \
	   $(wildcard gnl/*.c) \
	   $(wildcard ft_printf/*.c)

OBJECTS = $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJECTS)
	ar -rc $(NAME) $(OBJECTS)

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
