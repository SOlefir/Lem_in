/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 12:47:11 by solefir           #+#    #+#             */
/*   Updated: 2019/07/28 21:11:04 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct	s_data		t_data;
typedef struct	s_graph		t_graph;
typedef struct	s_way		t_way;

struct			s_data
{
	char		**rooms;
	int			**links;
};

struct			s_graph
{
	char		*name;
	int			index;
	int			count_steps; // поумолчанию g_count_links. дейкстра меняет это число
	int			*links;//индекс комнаты с которой линк
};

struct			t_way
{
	
};


#endif