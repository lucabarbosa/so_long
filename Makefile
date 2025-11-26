NAME		=	so_long
CC			=	@cc
CFLAGS		=	-Wall -Wextra -Werror
MLX			=	mlx/libmlx_Linux.a
LIBFT		=	libft/libft.a
INC			=	-I ./src -I ./libft -I ./mlx
LIBS		=	-L ./libft -l:libft.a -L ./mlx -lmlx -lXext -lX11 -lm -lbsd
OBJ			=	$(patsubst src/%.c, obj/%.o, $(SRC))
SRC			=	src/struct_init.c \
				src/free_game.c \
				src/get_map.c \
				src/hand_map.c \
				src/map_valid.c \
				src/convert_map.c \
				src/solvable_map.c \
				src/draw.c \
				src/update.c \
				src/press_keys.c \
				src/movements.c \
				src/so_long.c

all:		$(MLX) $(LIBFT) obj $(NAME)

$(NAME):	$(OBJ)
			$(CC) $(CFLAGS) -o $@ $^ $(LIBS)
			@echo "\033[1;32m✅ so_long compiled!\033[0m"

$(MLX):
			@make -s -C mlx
			@echo "\033[1;32m✅Minilibx compiled!\033[0m"

$(LIBFT):		
			@make -s -C libft
			@echo "\033[1;32m✅Libft compiled!\033[0m"

obj:
			@mkdir -p obj

obj/%.o:	src/%.c
			$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
			@make -s $@ -C libft
			@make -s $@ -C mlx
			@rm -rf $(OBJ) obj
			@echo "\033[1;31mObjects deleted.\033[0m"

fclean:		clean
			@make -s $@ -C libft
			@rm -rf $(NAME)
			@echo "\033[1;31mObjects and so_long deleted.\033[0m"

re:			fclean all

.PHONY:		all clean fclean re