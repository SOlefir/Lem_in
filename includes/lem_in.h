/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 12:42:21 by solefir           #+#    #+#             */
/*   Updated: 2019/07/20 21:16:01 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	LEM_IN_H
# define LEM_IN_H
# include "libft.h"
# include "structures.h"

/*
**		MACROSES:
*/
# define FD 0

/*
**		GLOBAL VARIABLES:
*/

int		g_count_lems = 0;
int		g_count_room = 0;
int		g_count_links = 0;

int     g_start = 0;
int     g_end = 0;

int**	g_arr_of_links = NULL;

/*
**		FUNCTIONS:
*/

int			read_and_valid(t_list *input);
int			errors(int error_nbr);

_Bool       is_room(char *str);
_Bool       uniq_coordinates(char *str, t_list *input);
_Bool       is_link(char *str);
_Bool       is_comand(char *str);
_Bool       is_comment(char *str);

void		get_data(t_data *farm, char *data);
t_room*		make_list_rooms(t_data *farm);
void		make_global_arr_links(t_room *rooms, t_data *farm);
t_ways*		make_list_all_ways(t_data *farm);
void		let_go_lemins(t_data *farm, t_ways *all_ways);

#endif