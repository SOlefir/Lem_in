# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: solefir <solefir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/11 21:25:16 by dquitzon          #+#    #+#              #
#    Updated: 2019/08/06 16:03:20 by solefir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

DIR = ./src/
HEADER = includes/lem_in.h includes/structures.h #includes/libft.h
LIB = libft.a

SOURCES = $(DIR)main.c $(DIR)validation.c $(DIR)validation_help.c\
		$(DIR)atoi_coordinates.c  $(DIR)errors.c $(DIR)validation_dop.c\
		$(DIR)write_in_lst.c $(DIR)find.c $(DIR)counts.c\
		$(DIR)new.c $(DIR)make_graph.c\
		$(DIR)test.c $(DIR)cut_coordinates.c\
		#$(DIR)edit_graph.c

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
		