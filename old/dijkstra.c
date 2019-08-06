/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 22:08:50 by solefir           #+#    #+#             */
/*   Updated: 2019/08/06 15:50:26 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void			add_way(t_ways **ways, int *short_way, int size_way)
{
	t_ways	*temp;

	temp = *ways;
	if ((*ways) == NULL)
	{
		(*ways) = (t_ways*)ft_memalloc(sizeof(t_ways));
		(*ways)->len_way = size_way;
		(*ways)->way = short_way;
		(*ways)->next = NULL;
	}
	else
	{
	    while ((*ways)->next != NULL)
	        (*ways) = (*ways)->next;
		(*ways) = (t_ways*)ft_memalloc(sizeof(t_ways));
		(*ways)->len_way = size_way;
		(*ways)->way = short_way;
		(*ways)->next = NULL;
	    *ways = temp;
    }
}

void			count_steps_to_end(t_room **graph)
{
	t_room	*room;
	t_room	*back;
	int		i;
	int		j;
	int		step;

	i = -1;
	step = 0;
	room = graph[0];
	room->count_steps = 0;
	while (step <= room->count_steps)
	{
		i = -1;
		step++;
		while (++i < room->count_links)
		{
			while (room->links[i] < 0 && i < room->count_links)
				i++;
			if (i >= room->count_links)
				room = graph[room->links[i]];
			else
				break;
			if (room->count_steps <= step)
				room->count_steps = step;
		}
		while ()
		room = graph[]
	}
}

/*
  while (room->links[j] < 0)
			j++;
		if (j >= room->links)
			break;
*/

static int			find_short_way(t_room **graph, int **way)
{
	t_room 	*room;
	int 	size_way;
	int 	i;

	room = graph[g_count_room - 1];
	size_way = graph[is_min_steps(graph, room)]->count_steps + 1;
	*way = (int*)ft_memalloc(sizeof(int) * (size_way + 1));
	i = size_way;
	(*way)[i] = room->index;
	while (--i >= 0)
	{
		(*way)[i] = is_min_steps(graph, room);
		room = graph[(*way)[i]];
	}
	return (++size_way);
}

/*_ways				*dijkstra(t_room ***graph)
{
	t_ways	*ways;
	int		size_way;
	int		count_ways;
	int		*short_way;
	int		i;

	ways = NULL;
	count_ways = max_allowable(*graph);
	count_steps_to_end(*graph);
	while (--count_ways >= 0)
	{
		size_way = find_short_way(*graph, &short_way);
		if ((i = is_bottle_neck(ways, short_way)))
		{
			(*graph)[short_way[i]]->links[short_way[i + 1]] = -1;
			ft_memdel((void**)&short_way);
			continue;
		}
		if (is_effective_way(ways, size_way))
			add_way(&ways, short_way, size_way);
		else
		{
			ft_memdel((void**)&short_way);
			break;
		}
		print_graph(*graph);
		edit_graph(graph, short_way, size_way);//направление для короткого пути поменять +
		printf("\nafter edit\n\n");
		print_graph(*graph);
		print_way(short_way, size_way);
	}											//во всем графе поменять каунт степс на максимум и добавить в этот цикл просчет шагов
	return (ways);
}
*/