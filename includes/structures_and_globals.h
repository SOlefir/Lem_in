/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures_and_globals.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 12:47:11 by solefir           #+#    #+#             */
/*   Updated: 2019/08/08 16:54:59 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_AND_GLOBALS_H
# define STRUCTURES_AND_GLOBALS_H

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

int		g_efficiency;
int		g_mod;

/*
**		STRUCTURES:
*/

typedef struct	s_room		t_room;
typedef struct	s_way		t_way;

struct			s_room
{
	char		*name;
	int			index;
	int			count_links;
	int			*links;
	t_way		*occup;
};

struct			s_way
{
	int			id;
	int			len;
	int			ant_inside;
	t_way		*parent;
	t_way		*next;
};

#endif