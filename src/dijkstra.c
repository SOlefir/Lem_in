/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 22:08:50 by solefir           #+#    #+#             */
/*   Updated: 2019/07/30 18:25:26 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void			count_steps_to_end(t_graph ***graph, int s)//проверить эту функцию. правильно ли работает рекурссия
{
	int i;
	int j;
	int	step;
	t_graph	**temp;
	t_graph *room;

	j = 0;
	i = 0;
	step = s;
	temp = graph;
	room = temp[g_start_room];
	while (room->count_steps > step)
	{
		while (temp[i]->links[j] != NULL)
		{
			room = temp[i]->links[j];
			room->count_steps = room->count_steps > step ?
								step : room->count_steps;
			j++;
			count_steps_to_end(&temp[i]->links[j], ++step);
		}
		j = 0;
		i++;
	}
}

static int			*find_short_way(t_graph **graph)
{
	int			j;
	int			i;
	t_graph		*room;
	t_graph		*back;
	int			*way;

	j = -1;
	i = -1;
	count_steps_to_end(&graph, 0);
	room = graph[g_end_room];
	way = (int*)ft_memalloc(sizeof(int) * room->count_steps + 1);
	way[room->count_steps] = NULL;
	while (room->links[++j] != NULL)
	{
		way[++i] = room->index;
		back = room;
		room = room->links[j];
		if (back->count_steps <= room->count_steps)
			room = back->links[j];
	}
	return (revers(&way));
}

t_ways				*dijkstra(t_graph ***graph)
{
	t_ways	**ways;
	t_ways	*temp;
	int		*short_way;
	int		i;

	short_way = NULL;
	while (short_way = find_short_way(*graph))
	{
		if (i = is_buttle_neek(ways, short_way))
		{
			(*graph)[short_way[i]]->links[short_way[i +1]] = -1;
			ft_memdel((void**)&short_way);
			continue;
		}
		if (is_effective_way(ways, short_way))
			ways = add_way(&short_way);
		else
		{
			ft_memdel((void**)&short_way);
			break;
		}
		edit_graph(graph, short_way);//направление для короткого пути поменять + 
									//во всем графе поменять каунт степс на максимум
	}
	return (ways);
}
