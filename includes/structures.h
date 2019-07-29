/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 12:47:11 by solefir           #+#    #+#             */
/*   Updated: 2019/07/29 21:15:24 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct	s_data		t_data;
typedef struct	s_graph		t_graph;
typedef struct	s_ways		t_ways;

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

struct			t_ways
{
	int		*way;
	int		effectivity;
	t_ways	*next;
};
#endif