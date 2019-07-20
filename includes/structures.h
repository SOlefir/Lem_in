/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 12:47:11 by solefir           #+#    #+#             */
/*   Updated: 2019/07/20 16:37:09 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct	s_data	t_data;
typedef struct	s_room	t_room;
typedef struct	s_way	t_way;
typedef struct	s_ways	t_ways;

struct	s_data
{
	char	*farm;
	t_data*	next;
};

struct	s_room
{
	char*	name;
	int		index;
	int		way;
	t_room	**next;
};

struct	s_way
{
	int		count_step;
	t_room	*room;
	t_way	*next;
};

struct	s_ways
{
	int		index;
	t_way	*way;
	t_ways	*next;
};

#endif