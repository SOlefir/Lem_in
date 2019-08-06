/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 12:42:21 by solefir           #+#    #+#             */
/*   Updated: 2019/08/06 18:02:28 by solefir          ###   ########.fr       */
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
int 	g_count_links;

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


t_list		*validation_and_write_in_lst(void);
t_room		**make_graph(t_list *input);
t_way		*dijkstra(t_room ***graph);

_Bool		last_validation(t_list *head);
void		write_in_list(t_list **head, t_list *new);
int			errors(void);

int			atoi_coordinates(char *str);
char		*cut_coordinates(char *room_name);

_Bool       is_room(char *str);
_Bool       is_link(char *str);
_Bool       is_comand(char *str);
_Bool       is_comment(char *str);
_Bool		is_unknown(char *str);

int			count_links_room(t_list *input, char *str);
int			max_allowable(t_room **graph);
void		count_steps_to_end(t_room **graph);

t_list		*find_link_in_lsts(t_list *list, char *str);
int			*find_links_room(char *name, t_list *input, 
								t_room **graph, int count_links);
#endif