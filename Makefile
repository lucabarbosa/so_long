NAME		=	so_long
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
MLX			=	mlx/Makefile.mk
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
				src/mlx_utils.c \
				src/so_long.c

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