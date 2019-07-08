# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: solefir <solefir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/22 17:51:25 by solefir           #+#    #+#              #
#    Updated: 2019/07/08 16:18:46 by solefir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

CC = gcc -Wall -Wextra -Werror -I ./lem-in.h -I ./libft/libft.h

SRC = ./libft/ft_bzero.c ./libft/ft_strlen.c ./libft/ft_strncpy.c\
	./libft/ft_memalloc.c ./libft/ft_strsub.c ./libft/ft_strdup.c\
	./libft/ft_strjoin.c ./libft/ft_strchr.c ./libft/ft_itoa.c\
	./libft/ft_putnbr.c ./libft/ft_putchar.c ./libft/ft_masmemdel.c\
	./libft/ft_strdel.c ./get_next_line.c\
	./main.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $^ -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
