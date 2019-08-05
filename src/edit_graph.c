/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_graph.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 14:04:03 by solefir           #+#    #+#             */
/*   Updated: 2019/08/05 15:36:21 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void		del_link(t_room **room, int	link)
{
	int	j;

	j = 0;
	while ((*room)->links[j] < (*room)->count_links &&
			(*room)->links[j] != link)
			j++;
	(*room)->links[j] = -1;
}

void			edit_graph(t_room ***graph, int *short_way, int size_way)
{
	t_room	*room;
	int 	i;

	i = 0;
	del_link(&(*graph)[short_way[i]], short_way[i + 1]); //удалить линк со стартом
	while (++i < size_way)
		del_link(&(*graph)[short_way[i]], short_way[i - 1]); // меняю направление для пути удаля линки с перентами
	i -= 2;
	del_link(&(*graph)[short_way[i]], short_way[i - 1]); // удалить линк с эндом
}
	
	


	
/*	t_room	*room;
	int 	j;
	int		i;

	i = 0;
	j = 0;
	room = (*graph)[short_way[i]];
	while (room->links[j] != short_way[i + 1] && room->links[j] > 0)
		j++;
	(*graph)[short_way[i]]->links[j] = -1;
	while (++i <= size_way)
	{
		room = (*graph)[short_way[i]];
		j = 0;
		while (room->links[j] != short_way[i - 1])
			j++;
		if (room->links[j] < 0)
			continue;
		(*graph)[short_way[i]]->links[j] = -1;
	}
	room = (*graph)[short_way[size_way - 1]];
	while (room->links[j] != short_way[size_way - 2] && room->links[j] > 0)
		j++;
	if (room->links[j] > 0)
		(*graph)[short_way[i]]->links[j] = -1;
	i = 0;
	while (++i < g_count_room)
		(*graph)[i]->count_steps = g_count_links;*/
