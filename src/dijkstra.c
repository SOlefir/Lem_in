/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 22:08:50 by solefir           #+#    #+#             */
/*   Updated: 2019/07/31 20:15:40 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void			add_way(t_ways **ways, int *short_way)
{
	t_ways	*temp;

	temp = *ways;
	if ((*ways) == NULL)
	{
		(*ways) = (t_ways*)ft_memalloc(sizeof(t_ways));
		(*ways)->len_way = count_len_way(short_way);
		(*ways)->way = short_way;
		(*ways)->next = NULL;
	}
	else
	{
	    while ((*ways)->next != NULL)
	        (*ways) = (*ways)->next;
		(*ways) = (t_ways*)ft_memalloc(sizeof(t_ways));
		(*ways)->len_way = count_len_way(short_way);
		(*ways)->way = short_way;
		(*ways)->next = NULL;
	    *ways = temp;
    }
}

static void			edit_graph(t_room ***graph, int *short_way)
{
	t_room	*room;
	int		i;
	int		j;
	int		k;

	i = -1;
	while ((*graph)[++i] != NULL)
	{
		j = -1;
		room = (*graph)[i];
		while (room->links[++j] != NULL)
		{
			k = -1;
			while (short_way[++k] != NULL)
				if (room->links[j] == short_way[k]) // проверить как передвигается по линкам дейкстра и возможно добавить проверку на -1 
					room->links == -1; //или инначе удалять ссылки
		}
	}
}

static void			count_steps_to_end(t_room ***graph, int step)//проверить эту функцию. правильно ли работает рекурссия
{
	int 	i;
	int 	j;
	t_room	**temp;
	t_room 	*room;

	j = 0;
	i = 0;
	temp = graph;
	room = temp[0];
	while (room->count_steps > step)
	{
		while (temp[i]->links[j] != NULL)
		{
			room = temp[i]->links[j];
			room->count_steps = room->count_steps > step ?
								step : room->count_steps;
			j++;
			count_steps_to_end(&(temp[i]->links[j]), ++step);
		}
		j = 0;
		i++;
	}
}

static int			*find_short_way(t_room **graph)
{
	int			j;
	int			i;
	t_room		*room;
	t_room		*back;
	int			*way;

	j = -1;
	i = -1;
	count_steps_to_end(&graph, 0);
	room = graph[g_count_room - 1];
	way = (int*)ft_memalloc(sizeof(int) * room->count_steps + 1);
	way[room->count_steps] = NULL;
	while (room->links[++j] != NULL)
	{
		way[++i] = room->index;
		back = room;
		room = graph[room->links[j]];//поставить проверку на -1
		if (back->count_steps <= room->count_steps)
			room = back->links[j];
	}
	revers(&way);
	return (way);
}

t_ways				*dijkstra(t_room ***graph)
{
	t_ways	*ways;
	int		count_ways;
	int		*short_way;
	int		i;

	ways = NULL;
	count_ways = max_allowable((*graph)[0]->links,
								(*graph)[g_count_room - 1]->links);
	while (--count_ways >= 0)
	{
		short_way = find_short_way(*graph);
		if (i = is_bottle_neck(ways, short_way))
		{
			(*graph)[short_way[i]]->links[short_way[i + 1]] = -1;
			ft_memdel((void**)&short_way);
			continue;
		}
		if (is_effective_way(ways, short_way))
			add_way(&ways, short_way);
		else
		{
			ft_memdel((void**)&short_way);
			break;
		}
		edit_graph(graph, short_way);//направление для короткого пути поменять + 
	}								//во всем графе поменять каунт степс на максимум
	return (ways);
}
