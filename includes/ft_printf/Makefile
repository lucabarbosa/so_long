# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbento <lbento@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/05 00:42:29 by lbento            #+#    #+#              #
#    Updated: 2025/08/06 11:13:05 by lbento           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CPPFLAGS = -I.
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c ft_putchar_printf.c ft_putnbr_printf.c ft_putnbr_u.c \
		ft_putstr_printf.c ft_strchr.c ft_pointerhex.c ft_putnbr_hex.c

OBJS = $(SRCS:.c=.o)

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

$.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
