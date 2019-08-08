# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: solefir <solefir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/11 21:25:16 by dquitzon          #+#    #+#              #
#    Updated: 2019/08/08 19:58:21 by solefir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

DIR = ./src/
HEADER = includes/lem_in.h includes/structures_and_globals.h #includes/libft.h
LIB = ./libft.a

SOURCES = $(DIR)main.c $(DIR)validation.c $(DIR)validation_help.c			\
		$(DIR)atoi_coordinates.c  $(DIR)errors.c $(DIR)validation_dop.c		\
		$(DIR)find.c $(DIR)counts.c	$(DIR)copy_lists.c $(DIR)calculate_eff.c\
		$(DIR)dijkstra.c $(DIR)make_graph.c $(DIR)for_lists.c 				\
		$(DIR)print_map.c $(DIR)cut_coordinates.c $(DIR)let_ants_move_and_print.c\
		$(DIR)untangle_ways.c $(DIR)let_ants_go.c			\

OBJ = $(SOURCES:%.c=%.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(FLAGS) -c $(SOURCES) -I $(HEADER)
	gcc $(OBJ) $(LIB) -o $@
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
		