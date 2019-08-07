/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 12:42:21 by solefir           #+#    #+#             */
/*   Updated: 2019/08/07 19:26:31 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	LEM_IN_H
# define LEM_IN_H
# include "libft.h"
# include "structures_and_globals.h"

# include <fcntl.h>//
# include <stdio.h>//

/*
**		FUNCTIONS:
*/

///////////////////////////////////////////////////////

void		out_ways(t_room **graph, t_way *meta);
void		test(t_list *input);
void		print_graph(t_room **graph);

///////////////////////////////////////////////////////


t_list		*validation_and_write_in_lst(void);
t_room		**make_graph(t_list *input);
t_way		*dijkstra(t_room ***graph);

int			untangle_ways1(t_room **graph, t_way **way);
int			untangle_ways2(t_room **graph, t_way **way);

_Bool		last_validation(t_list *head);
int			errors(void);

int			atoi_coordinates(char *str);
char		*cut_coordinates(char *room_name);

_Bool       is_room(char *str);
_Bool       is_link(char *str);
_Bool       is_comand(char *str);
_Bool       is_comment(char *str);
_Bool		is_unknown(char *str);

int			max_allowable(t_room **graph);
int			count_links_room(t_list *input, char *str);
void		count_steps_to_end(t_room **graph);

t_list		*find_link_in_input(t_list *list, char *str);
int			*find_links_room(char *name, t_list *input, 
								t_room **graph, int count_links);

void		write_in_list(t_list **head, t_list *new);
t_way		*new_list(int id, t_way *parent);
void		del_list(t_way **list);
int			len_way(t_way *way);

#endif