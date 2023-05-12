# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/07 12:25:40 by ftomaz-c          #+#    #+#              #
#    Updated: 2023/05/12 16:48:34 by ftomaz-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

LIB_CMD = ar -rcs

NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror -Ilibft

SRC =	ft_printf.c			flag_check.c		flag_width.c		\
		flag_precision.c	flag_alternative.c	format_specifier.c	\
		format_char.c		format_str.c		format_ptr.c		\
		format_nbr.c		format_unsg.c		format_hex.c		\
		format_hex2.c												\

##BSRC =	flag_check.c 		flag_width.c 		flag_precision.c	\
		flag_alternative.c	format_specifier.c						\

OBJ = $(SRC:.c=.o)

##BOBJ = $(SRC:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(MAKE) -C libft
	cp libft/libft.a $(NAME)
	$(LIB_CMD) $(NAME) $(OBJ)

all: $(NAME)

##bonus: $(OBJ) $(BOBJ)
	$(MAKE) -C libft
	cp libft/libft.a $(NAME)
	$(LIB_CMD) $(NAME) $(OBJ) $(BOBJ)

clean:
	rm -rf $(OBJ)
	$(MAKE) -C libft clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re bonus
