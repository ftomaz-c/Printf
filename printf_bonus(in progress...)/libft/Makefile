# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/12 12:23:08 by pmessett          #+#    #+#              #
#    Updated: 2023/05/12 13:51:29 by ftomaz-c         ###   ########.fr        #
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

SRC =	ft_isalpha.c	ft_isdigit.c		ft_isalnum.c	ft_isascii.c	ft_isprint.c	\
		ft_strlen.c		ft_memset.c			ft_bzero.c		ft_memcpy.c		ft_strlcat.c	\
		ft_memmove.c	ft_strlcpy.c		ft_strlcat.c	ft_toupper.c	ft_tolower.c	\
		ft_strchr.c		ft_strrchr.c		ft_strncmp.c	ft_memchr.c		ft_memcmp.c		\
		ft_strnstr.c	ft_atoi.c			ft_calloc.c		ft_strdup.c		ft_substr.c		\
		ft_strjoin.c	ft_strtrim.c		ft_split.c		ft_itoa.c		ft_strmapi.c	\
		ft_striteri.c	ft_putchar_fd.c		ft_putstr_fd.c	ft_putendl_fd.c	ft_putnbr_fd.c	\
		ft_putnstr_fd.c	ft_putnbr_base_fd.c													\

BSRC =	ft_lstnew.c		ft_lstadd_front.c	ft_lstsize.c	ft_lstlast.c	ft_lstadd_back.c\
		ft_lstdelone.c 	ft_lstclear.c 		ft_lstiter.c 	ft_lstmap.c 					\

OBJ = $(SRC:.c=.o)

BOBJ = $(BSRC:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(NAME):	$(OBJ)
	$(LIB_CMD) $(NAME) $(OBJ)

all:		$(NAME)

bonus:		$(OBJ) $(BOBJ)
	$(LIB_CMD) $(NAME) $(OBJ) $(BOBJ)

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all

.PHONY: all clean fclean re bonus
