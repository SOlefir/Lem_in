# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: solefir <solefir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/11 21:25:16 by dquitzon          #+#    #+#              #
#    Updated: 2019/08/01 18:47:36 by solefir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

DIR = ./src/
HEADER = includes/lem_in.h includes/structures.h includes/libft.h
LIB = libft.a

SOURCES = $(DIR)main.c $(DIR)validation.c $(DIR)validation_help.c\
		$(DIR)atoi_coordinates.c  $(DIR)errors.c $(DIR)validation_dop.c\
		$(DIR)write_in_lst.c\
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

#$(DIR)find.c\#
		
		#$(DIR)cheack_way.c $(DIR)counts.c $(DIR)dijkstra.c $(DIR)divorce.c
		#$(DIR)disjoint_path_finding.c $(DIR)make_graph.c $(DIR)revers.c\#