# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/07 12:25:40 by ftomaz-c          #+#    #+#              #
#    Updated: 2023/05/09 19:16:18 by ftomaz-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

LIB_CMD = ar -rcs

NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror -I.

SRC =	ft_printf.c		flag_check.c	is_flags.c		is_placeholder.c	\
		str_format.c	ptr_format.c										\

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
