# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/07 12:25:40 by ftomaz-c          #+#    #+#              #
#    Updated: 2023/05/08 22:24:55 by ftomaz-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

LIB_CMD = ar -rcs

NAME = printf.a

CFLAGS = -Wall -Wextra -Werror -I.

SRC = printf.c flag_check.c flags.c is_placeholder.c \

OBJ = $(SRC:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
$(NAME): $(OBJ)
	$(MAKE) -C libft
	$(LIB_CMD) $(NAME) $(OBJ) libft/*.o

all: $(NAME)

clean:
	rm -rf $(OBJ)
	$(MAKE) -C libft clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re
