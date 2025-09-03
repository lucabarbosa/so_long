NAME = so_long
SRC = $(addprefix src/, main.c utils.c draw.c map_parser.c path_checker.c game_utils.c map_parser_utils.c free.c)
GNL_SRC = $(addprefix includes/gnl/, get_next_line.c get_next_line_utils.c)
PRINTF_SRC = $(addprefix includes/ft_printf/, ft_printf.c ft_putchar_printf.c ft_putnbr_printf.c ft_putnbr_u.c \
		ft_putstr_printf.c ft_strchr.c ft_pointerhex.c ft_putnbr_hex.c)

OBJ := $(SRC:%.c=%.o)
GNL_OBJ := $(GNL_SRC:%.c=%.o)
PRINTF_OBJ := $(PRINTF_SRC:%.c=%.o)

CC = cc
CCFLAGS = -Wextra -Wall -Werror

all: $(NAME)

$(NAME): $(OBJ) $(GNL_OBJ) $(PRINTF_OBJ)
    $(CC) $(CCFLAGS) $^ -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	cc $(CCFLAGS) -Imlx -Iincludes -c $< -o $@

clean:
	rm -f $(OBJ) $(GNL_OBJ) $(PRINTF_OBJ)

fclean: clean
	make clean -C mlx/
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re mlx libft

#https://github.com/42Paris/minilibx-linux