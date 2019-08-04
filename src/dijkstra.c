/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 22:08:50 by solefir           #+#    #+#             */
/*   Updated: 2019/08/04 15:41:33 by solefir          ###   ########.fr       */
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
		while (++j <= room->count_links)
		{
			k = -1;
			while (short_way[++k] < (*graph)[i]->count_steps)
				if (room->links[j] == short_way[k]) // проверить как передвигается по линкам дейкстра и возможно добавить проверку на -1 
					room->links[j] = -1; //или инначе удалять ссылки
		}
	}
}

static void			count_steps_to_end(t_room **graph)
{
	int 	j;
	int 	step;
	t_room	*room;
	t_room	*link;

	step = 0;
	room = graph[0];
	room->count_steps = step;
	while (step <= room->count_steps)
	{
		j = -1;
		++step;
		while (++j < room->count_links)
		{
			link = graph[room->links[j]];
			link->count_steps = link->count_steps > step ? step : link->count_steps;
		}
		j = 0;
		while (room->links[j] < 0 || (graph[room->links[j]]->count_steps < step &&
															j < room->count_links))
			j++;
		if (j < room->count_links)
			room = graph[room->links[j]];
	}
}

/*
  while (room->links[j] < 0)
			j++;
		if (j >= room->links)
			break;
*/

static int			*find_short_way(t_room **graph)
{
	t_room *room;
	int *way;
	int size_way;

	room = graph[g_count_room - 1];
	size_way = graph[is_min_steps(graph, room)]->count_steps + 1;//попробуй изменить инициализацию степ с 0 на 1
	way = (int*)ft_memalloc(sizeof(int) * size_way + 1);//иначе посчитать длинну пути.
	way[size_way] = room->index;
	while (--size_way >= 0)
	{
		way[size_way] = is_min_steps(graph, room);//функция возвращает индекс комнаты, с которой ссылка у рум и мин кол-во шагов
		room = graph[way[size_way]];
	}

}


	/*{
		way[++i] = room->index;
		back = room;
		while (room->links[j] < 0)
			j++;
		if (j >= room->count_links)
			break;
		room = graph[room->links[j]];//прописать цикл, который сравнивает кол-во шагов именно ссылок комнаты.
		while ()
		if (back->count_steps <= room->count_steps)
			room = graph[back->links[j]];
	}
	room = graph[graph[g_count_room - 1]->links[way[0]]];
	reverse(&way, room->count_steps);//
	return (way);*/

t_ways				*dijkstra(t_room ***graph)
{
	t_ways	*ways;
	int		count_ways;
	int		*short_way;
	int		i;

	ways = NULL;
	count_ways = max_allowable(*graph);
	count_steps_to_end(*graph);
	while (--count_ways >= 0)
	{
		short_way = find_short_way(*graph);
		if ((i = is_bottle_neck(ways, short_way)))
		{
			(*graph)[short_way[i]]->links[short_way[i + 1]] = -1;
			ft_memdel((void**)&short_way);
			continue;
		}
		if (is_effective_way(ways, (*graph)[g_count_room]->count_steps))
			add_way(&ways, short_way, (*graph)[g_count_room]->count_steps);
		else
		{
			ft_memdel((void**)&short_way);
			break;
		}
	//	edit_graph(graph, short_way);//направление для короткого пути поменять +
	}		 					//во всем графе поменять каунт степс на максимум
	return (ways);
}

void	print_graf(t_room ***graph)
{
	int j = -1;
	int i = -1;
	while (++i < g_count_room)
	{
		printf("[%d]'%s' steps: %d\n", i, (*graph)[i]->name, (*graph)[i]->count_steps);
		/*while (++j < graph[i]->count_links)
			printf("(%d)", graph[i]->links[j]);*/
		j = -1;
		printf("\n");
	}
}