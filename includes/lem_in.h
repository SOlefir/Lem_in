/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 12:42:21 by solefir           #+#    #+#             */
/*   Updated: 2019/07/22 20:47:41 by solefir          ###   ########.fr       */
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

extern int		g_start;
extern int		g_end;

extern int		**g_arr_of_links;
extern int		fd;

/*
**		FUNCTIONS:
*/

void		test(t_list *input);
t_list		*make_list(char *str, int str_size);

int			read_and_valid(t_list *input);
int			errors(int error_nbr);
int			atoi_coordinates(char *str);

_Bool       is_room(char *str);
_Bool       is_link(char *str);
_Bool       is_comand(char *str);
_Bool       is_comment(char **str);

void		get_data(t_data *farm, char *data);
t_room*		make_list_rooms(t_data *farm);
void		make_global_arr_links(t_room *rooms, t_data *farm);
t_ways*		make_list_all_ways(t_data *farm);
void		let_go_ants(t_data *farm, t_ways *all_ways);

#endif