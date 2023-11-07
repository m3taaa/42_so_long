NAME		=	so_long
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
FLAG_MLX_LINUX = minilibx-linux/libmlx_Linux.a  -lX11 -lXext -L minilibx-linux/
SRCDIR		=	src/
OBJDIR		=	obj/
INCLUDE		=	header/

SRC			=	$(wildcard src/*.c)
					
OBJ			=	$(SRC:%.c=%.o)


# ===== #


all:			$(NAME)

$(NAME):		$(OBJ)
				$(CC) $(OBJ) $(FLAG_MLX_LINUX) libft_and_more/libft_and_more.a -o $(NAME)

clean:
				rm $(OBJ) 

fclean:			
				rm $(NAME) $(OBJ)

re:				fclean all

%.o:	%.c
				$(CC) $(CFLAGS) -c $< -o $@


.PHONY:			re clean fclean objs all
