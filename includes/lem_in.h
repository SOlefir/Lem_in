/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 12:42:21 by solefir           #+#    #+#             */
/*   Updated: 2019/07/28 20:59:29 by solefir          ###   ########.fr       */
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
int		g_count_ways;

int		g_start;
int		g_end;

int		g_start_links;
int		g_end_links;

char		**g_rooms;

int		g_error_nbr;
int		fd;//

/*
**		FUNCTIONS:
*/

void		test(t_list *input);

t_list		*validation_and_write_in_lst(void);
t_graph		**make_graph(t_list *input);

int			errors(void);
int			atoi_coordinates(char *str);

_Bool       is_room(char *str);
_Bool       is_link(char *str);
_Bool       is_comand(char *str);
_Bool       is_comment(char *str);
_Bool		is_unknown(char *str);

void		dijkstra();
void		bhandari();

#endif