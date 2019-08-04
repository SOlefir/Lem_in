/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_min_steps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 20:20:09 by solefir           #+#    #+#             */
/*   Updated: 2019/08/04 20:29:16 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int			is_min_steps(t_room **graph, t_room *room)
{
	int	index;
	int	steps;
	int	i;

	i = 0;
	if (room->links[i] < 0)
		i++;
	steps = graph[room->links[i]]->count_steps;
	index = room->links[i];
	i = 0;
	while (++i < room->count_links)
	{
		if (room->links[i] < 0)
			i++;
		if (i < room->count_links &&
			graph[room->links[i]]->count_steps < steps)
		{
			index = room->links[i];
			steps = graph[room->links[i]]->count_steps;
		}
	}
	return (index);
}
