/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 12:47:11 by solefir           #+#    #+#             */
/*   Updated: 2019/07/26 17:14:32 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct	s_struct_d	t_struct_d;
typedef struct	s_graph		t_graph;
typedef struct	s_dijkstra	t_dijkstra;

struct			s_struct_d
{
	char		**rooms;
	int			**links;
};

struct			s_graph
{
	int			room_index;
	int			count_steps; // поумолчанию g_count_links. дейкстра меняет это число
	t_graph		**links;
};

struct			s_dijkstra
{
	int			**got_rooms;
	
};


#endif