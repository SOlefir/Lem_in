/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 12:42:21 by solefir           #+#    #+#             */
/*   Updated: 2019/07/26 17:08:52 by solefir          ###   ########.fr       */
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

extern int		g_count_ants;
extern int		g_count_room;
extern int		g_count_links;
extern int		g_count_ways;

extern int		g_start;
extern int		g_end;

extern int		g_start_links;
extern int		g_end_links;

extern int		g_error_nbr;
extern int		fd;//

/*
**		FUNCTIONS:
*/

void		test(t_list *input);

t_list		*validation_and_write_in_lst(void);
t_data		*get_data(t_list *input);
int			errors(int error_nbr);
int			atoi_coordinates(char *str);

_Bool       is_room(char *str);
_Bool       is_link(char *str);
_Bool       is_comand(char *str);
_Bool       is_comment(char *str);

void		dijkstra();
void		bhandari();

#endif