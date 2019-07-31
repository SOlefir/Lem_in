/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 12:42:21 by solefir           #+#    #+#             */
/*   Updated: 2019/07/31 20:49:23 by solefir          ###   ########.fr       */
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

void		test(t_list *input);//

t_list		*validation_and_write_in_lst(void);
t_room		**make_graph(t_list *input);

int			errors(void);
int			atoi_coordinates(char *str);

_Bool       is_room(char *str);
_Bool       is_link(char *str);
_Bool       is_comand(char *str);
_Bool       is_comment(char *str);
_Bool		is_unknown(char *str);

_Bool		is_buttle_neek(t_ways *ways, int *short_way);
_Bool		is_effective_way(t_ways *ways, int *new_way);

int			count_lst(t_ways *lst);
int			count_all_steps(t_ways *ways);
int			count_len_way(int *way);

void		revers(int *way);
int			max_allowable(int *start, int *end);

t_ways		*disjoint_path_finding(t_room ***graph);
t_ways		*dijkstra(t_room ***graph);

int			*find_links_room(char *name, t_list *input, t_room **graph);

#endif