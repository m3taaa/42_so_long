NAME = so_long

CC = gcc

SRCS =	src/main.c\
		src/check_file.c\
		src/utils.c\
		src/check_map.c\
		src/start_game.c\
		src/print_element.c\
		src/move.c\
		src/check_path.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Werror -Wextra -Wall

MLXFLAGS_MAC = -Lmlx -lmlx -framework OpenGL -framework AppKit

INCLUDES = libft/libft_and_more.a mlx/libmlx.a

all: $(NAME)

$(NAME): $(OBJS)
		@make -C libft/ > /dev/null 2>&1
		@make -C mlx/ > /dev/null 2>&1
		@$(CC) $(OBJS) $(INCLUDES) $(MLXFLAGS_MAC) -o $(NAME)
		@echo "create so_long"

clean:
	@make -C libft/ clean > /dev/null 2>&1
	@make -C mlx/ clean > /dev/null 2>&1
	@rm -f $(OBJS) > /dev/null 2>&1
	@echo "delete files *.o"

fclean: clean
	@make -C libft/ fclean > /dev/null 2>&1
	@rm $(NAME) > /dev/null 2>&1
	@echo "delete so_long"

re: fclean all

.PHONY:	all clean fclean re
