/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 15:52:16 by solefir           #+#    #+#             */
/*   Updated: 2019/08/06 21:46:32 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_way		*new_list(int id, t_way *parent)
{
	t_way	*new;

	new = malloc(sizeof(t_way));
	new->id = id;
	new->parent = parent;
	new->next = NULL;
	return (new);
}


int			check_presence(t_way *list, int id)
{
	while (list)
	{
		if (id == list->id)
			return (0);
		list = list->next;
	}
	return (1);
}

t_way			*create_lists_of_links(t_room ***graph)
{
	t_way	*list;
	t_way	*step;
	t_way	*front;
	int		*link;
	int		i;

	list = new_list(g_count_room - 1, NULL);
	step = list;
	front = list;
	while (step)
	{
		link = (*graph)[step->id]->links;
		i = 0;
		while (i < (*graph)[step->id]->count_links)
		{
			if (link[i] != -1 && check_presence(list, link[i]))
			{
				front->next = new_list(link[i], step);
				front = front->next;
			}
			i++;
		}
		step = step->next;
	}
	return (list);
}

t_way			*new_way(t_room ***graph, t_way *list)
{
	t_way	*step;
	t_way	*front;
	t_way	*way;
	int		*link;
	int		i;

	list = create_lists_of_links(graph);
	step = list;
	while (step && step->id)
		step = step->next;
	front = NULL;
	if (step)
	{
		way = new_list(step->id, NULL);
		if (way->id && way->id != g_count_room - 1 && !(*graph)[way->id]->occup)
			(*graph)[way->id]->occup = way;
		front = way;
		while (step->parent)
		{
			way->parent = new_list(step->parent->id, NULL);
			way->parent->next = way;
			i = 0;
			link = (*graph)[step->parent->id]->links;
			while (i < (*graph)[step->parent->id]->count_links)
			{
				if (link[i] == step->id)
					link[i] = -1;
				i++;
			}
			way = way->parent;
			if (way->id && way->id != g_count_room - 1 && !(*graph)[way->id]->occup)
				(*graph)[way->id]->occup = way;
			step = step->parent;
		}
	}
	//del list
	return ((front && !front->id) ? front : NULL);
}

int					equalize(t_room **graph, t_way **way)
{
	t_way	*dupl;
	//t_way	*(from[2]);
	t_way	*from1;
	t_way	*to1;
	t_way	*from2;
	t_way	*to2;

	dupl = *way;
	while (dupl)
	{
		if (dupl->id && dupl->id != g_count_room - 1 &&
		graph[dupl->id]->occup != dupl && (to1 = dupl))
		{
			from1 = graph[dupl->id]->occup;
			//to1 = dupl;
			while (from1->id == to1->id && (from1 = from1->next))
					to1 = to1->parent;
			from2 = dupl;
			to2 = graph[dupl->id]->occup;
			while (from2->id == to2->id && (to2 = to2->parent))
					from2 = from2->next;
			//printf("FROM1->TO1: %d->%d\nFROM2->TO2: %d->%d\n\n\n", from1->id, to1->id, from2->id, to2->id);
			from1->parent->parent = to1;
			to1->next = from1->parent;
			from2->parent->parent = to2;
			to2->next = from2->parent;
		}
		dupl = dupl->parent;
	}
	return (1);
}

void				out_ways(t_way *meta)
{
	t_way	*path;
	t_way	*dupl;

	path = meta;
	while ((path = path->next))
	{
		dupl = path;
		while ((dupl = dupl->parent))
			printf("[%d] ", dupl->id);
		printf("\n\n");
	}
	printf("\nLOOP!\n\n\n");
}

t_way				*dijkstra(t_room ***graph)
{
	t_way	*meta;
	t_way	*path;

	meta = new_list(-1 , NULL);
	path = meta;
	while (path)
	{
		path->next = new_list(-1, NULL);
		path = path->next;
		if (!(path->parent = new_way(graph, 0)))
			break ;
		equalize(*graph, &(path->parent));
		out_ways(meta);
	}
	return (meta);
}
