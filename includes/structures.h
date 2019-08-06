/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 12:47:11 by solefir           #+#    #+#             */
/*   Updated: 2019/08/06 17:40:34 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

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
	t_way		*parent;
	t_way		*next;
};

#endif
