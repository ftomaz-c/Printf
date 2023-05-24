# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/12 12:23:08 by pmessett          #+#    #+#              #
#    Updated: 2023/05/24 16:11:37 by ftomaz-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

LIB_CMD = ar -rcs
#ar: create a static library archive:
# -r - create the archive;
# -c - update contents;
# -s - make the archive file.

NAME = libft.a

CFLAGS = -Wall -Wextra -Werror -I.

SRC =	ft_strlen.c			ft_putchar_fd.c		ft_putstr_fd.c		\
		ft_putnbr_fd.c		ft_putnbr_base_fd.c						\

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
