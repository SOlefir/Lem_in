# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: solefir <solefir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/11 21:25:16 by dquitzon          #+#    #+#              #
#    Updated: 2019/07/26 17:05:57 by solefir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

DIR = ./src/
HEADER = includes/lem_in.h includes/structures.h includes/libft.h
LIB = libft.a

SOURCES = $(DIR)main.c $(DIR)validation.c $(DIR)validation_help.c $(DIR)errors.c\
		$(DIR)atoi_coordinates.c  $(DIR)get_data.c\
		$(DIR)test.c\

OBJ = $(SOURCES:%.c=%.o)

FLAGS = -Wall -Wextra -Werror -c

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(FLAGS) -c $(SOURCES) -I $(HEADER)
	gcc -fsanitize="address" -g -fno-omit-frame-pointer $(OBJ) $(LIB) -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
