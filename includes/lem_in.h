/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 12:42:21 by solefir           #+#    #+#             */
/*   Updated: 2019/07/15 19:39:27 by solefir          ###   ########.fr       */
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

int**	arr_of_links;

/*
**		FUNCTIONS:
*/

int			validation(t_data *farm);
int			errors(int error_nbr);
void		get_data(t_data *farm, char *data);
t_room*		make_list_rooms(t_data *farm);
void		make_global_arr_links(t_room *rooms, t_data *farm);
t_ways*		make_list_all_ways(t_data *farm);
void		let_go_lemins(t_data *farm, t_ways *all_ways);

#endif