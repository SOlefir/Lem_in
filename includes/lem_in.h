/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 12:42:21 by solefir           #+#    #+#             */
/*   Updated: 2019/08/08 21:04:25 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "libft.h"
# include "structures_and_globals.h"

# include <fcntl.h>

/*
**		FUNCTIONS:
*/

void		out_ways(t_room **graph, t_way *meta);
void		print_graph(t_room **graph);

void		add_ant_and_print(int ant_id, t_way *ways, t_room **graph);
int			make_moves(t_way **ws);
void		print_moves(t_way **ws, t_room **graph);
t_way		**let_ants_go(t_way *ways, t_room **graph, int **how_much);

t_list		*validation_and_write_in_lst(void);
t_room		**make_graph(t_list *input);
t_way		*dijkstra(t_room ***graph);

int			untangle_ways(t_room ***graph, t_way **way);
int			calc_efficiency(t_way *meta);

_Bool		last_validation(t_list *head);
int			errors(void);

int			atoi_coordinates(char *str);
char		*cut_coordinates(char *room_name);

_Bool		is_room(char *str);
_Bool		is_link(char *str);
_Bool		is_comand(char *str);
_Bool		is_comment(char *str);
_Bool		is_unknown(char *str);

int			max_allowable(t_room **graph);
int			count_links_room(t_list *input, char *str);
void		count_steps_to_end(t_room **graph);

t_list		*find_link_in_input(t_list *list, char *str);
int			*find_links_room(char *name, t_list *input,
								t_room **graph, int count_links);

void		write_in_list(t_list **head, t_list *new);
void		del_list(t_way **list);
void		del_list_of_lists(t_way **list);
t_way		*new_list(int id, t_way *parent);
t_way		*copy_list(t_way *meta);
int			len_way(t_way *way);

void		print_map(t_list *input);

int			new_trash(t_way *elem);

#endif
