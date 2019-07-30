/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 12:47:11 by solefir           #+#    #+#             */
/*   Updated: 2019/07/30 21:34:33 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct	s_data		t_data;
typedef struct	s_room		t_room;
typedef struct	s_ways		t_ways;

struct			s_data
{
	char		**rooms;
	int			**links;
};

struct			s_room
{
	char		*name;
	int			index;
	int			count_steps; // поумолчанию g_count_links. дейкстра меняет это число
	int			*links;//индекс комнаты с которой линк
};

struct			s_ways
{
	int		*way;
	int		len_way;
	int		effectivity;
	t_ways	*next;
};

#endif