# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/07 12:25:40 by ftomaz-c          #+#    #+#              #
#    Updated: 2023/05/24 16:22:56 by ftomaz-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

LIB_CMD = ar -rcs

NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror -Ilibft

SRC =	ft_printf.c		str_format.c	format_len.c	ptr_format.c	\
		nbr_format.c	unsg_format.c	hex_format.c					\

OBJ = $(SRC:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(MAKE) -C libft
	cp libft/libft.a $(NAME)
	$(LIB_CMD) $(NAME) $(OBJ)

all: $(NAME)

clean:
	rm -rf $(OBJ)
	$(MAKE) -C libft clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re
