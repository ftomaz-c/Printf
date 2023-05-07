# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/07 12:25:40 by ftomaz-c          #+#    #+#              #
#    Updated: 2023/05/07 17:11:37 by ftomaz-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

LIB_CMD = ar -rcs
#ar: create a static library archive:
# -r - create the archive;
# -c - update contents;
# -s - make the archive file.

NAME = printf.a

CFLAGS = -Wall -Wextra -Werror -I. -I./libft

SRC =	flag_check.c ft_putchar_fd.c ft_putstr_fd ft_putnbr_base_fd \

OBJ = $(SRC:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(NAME):	$(OBJ)
	$(LIB_CMD) $(NAME) $(OBJ)

all:		$(NAME)

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all

.PHONY: all clean fclean re
