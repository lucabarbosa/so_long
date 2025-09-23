NAME		=	so_long
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
OBJ			=	$(patsubst src%, obj%, $(SRC:.c=.o))
SRC			=	src/struct_init.c \
				src/free_game.c \
				src/init_map.c \
				src/hand_map.c \
				src/map_valid.c \
				src/convert_map.c \
				src/

MLX			=	mlx/Makefile.gen
LIBFT			=	libft/libft.a
INC			=	-I ./libft -I ./mlx
LIBS			=	-L ./libft -LIBFT -L ./mlx -lmlx -lXext -lX11 -lm -lbsd

all:		$(MLX) $(LIBFT) obj $(NAME)

$(NAME):	$(OBJ)
			$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

$(MLX):
			@make -s -C mlx
			@echo "Minilibx compiled!"

$(LIBFT):		
			@make -s -C libft
			@echo "Libft compiled!"

obj:
			@mkdir -p obj

obj/%.o:	src/%.c
			$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
			@make -s $@ -C libft
			@rm -rf $(OBJ) obj
			@echo "Objects deleted."

fclean:		clean
			@make -s $@ -C libft
			@rm -rf $(NAME)
			@echo "Objects and so_long deleted."

re:			fclean all

.PHONY:		all clean fclean re
