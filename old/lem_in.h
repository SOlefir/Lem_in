/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 12:42:21 by solefir           #+#    #+#             */
/*   Updated: 2019/08/06 16:02:29 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	LEM_IN_H
# define LEM_IN_H
# include "libft.h"
# include "structures.h"

# include <fcntl.h>//
# include <stdio.h>
/*
**		MACROSES:
*/

/*
**		GLOBAL VARIABLES:
*/

int		g_count_ants;
int		g_count_room;
int		g_count_links;

int		g_start;
int		g_end;

int		g_error_nbr;
int		fd;//

/*
**		FUNCTIONS:
*/

///////////////////////////////////////////////////////

/*void 		print_int(int *arr, size_t size);
void		print_graph(t_room **graph);
void		print_ways(t_ways *ways);
void		print_way(int *way, int size_way);
void		test(t_list *input);
*/
///////////////////////////////////////////////////////

int			is_min_steps(t_room **graph, t_room *room);
t_list		*validation_and_write_in_lst(void);
void		write_in_list(t_list **head, t_list *new);
_Bool		last_validation(t_list *head);
int			errors(void);
char		*cut_coordinates(char *room_name);

t_room		**make_graph(t_list *input);
int			atoi_coordinates(char *str);

_Bool       is_room(char *str);
_Bool       is_link(char *str);
_Bool       is_comand(char *str);
_Bool       is_comment(char *str);
_Bool		is_unknown(char *str);

//_Bool		is_bottle_neck(t_ways *ways, int *short_way);
//_Bool				is_effective_way(t_ways *ways, int steps_new_way);

int			count_links_room(t_list *input, char *str);
//int			count_all_ways(t_ways *lst);
//int			count_all_steps(t_ways *ways);
int			max_allowable(t_room **graph);
void		count_steps_to_end(t_room **graph);

t_list		*find_link_in_lsts(t_list *list, char *str);
int			*find_links_room(char *name, t_list *input, 
								t_room **graph, int count_links);
/*
void		reverse(int **way, int size);
int			*divorce(t_ways *way_a, t_ways *way_b, int *start, int *end);
void		edit_graph(t_room ***graph, int *short_way, int size_way);

t_ways		*disjoint_path_finding(t_room ***graph);*/

t_way		*dijkstra(t_room ***graph);

#endif