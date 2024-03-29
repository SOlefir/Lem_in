/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 15:52:16 by solefir           #+#    #+#             */
/*   Updated: 2019/08/08 20:48:19 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		g_efficiency = 200000000;
int		g_mod = 0;

static int			check_presence(t_way *list, int id)
{
	int		n;
	int		m;

	n = 0;
	m = 0;
	while (list)
	{
		if (id == list->id)
			n = 1;
		if (list->parent && id == list->parent->id)
			m = 1;
		list = list->next;
	}
	return ((n == 1 && !m) ? 0 : n);
}

static t_way		*create_lists_of_links(t_room ***graph)
{
	t_way	*list;
	t_way	*step;
	t_way	*front;
	int		*link;
	int		i;

	list = new_list(g_count_room - 1, NULL);
	step = list;
	front = list;
	while (step && (i = -1))
	{
		link = (*graph)[step->id]->links;
		while (++i < (*graph)[step->id]->count_links)
		{
			if (link[i] != -1 && !check_presence(list, link[i]) &&
			!(step->parent && !(*graph)[step->parent->id]->occup &&
			!!(*graph)[step->id]->occup && !(*graph)[link[i]]->occup))
			{
				front->next = new_list(link[i], step);
				front = front->next;
			}
		}
		step = step->next;
	}
	return (list);
}

static t_way		*create_way(t_way *step, t_room ***graph)
{
	t_way	*way;
	t_way	*front;
	int		*link;
	int		i;

	way = new_list(step->id, NULL);
	new_trash(way);
	if (way->id && way->id != g_count_room - 1 && !(*graph)[way->id]->occup)
		(*graph)[way->id]->occup = way;
	front = way;
	while (step->parent && (i = -1))
	{
		way->parent = new_list(step->parent->id, NULL);
		new_trash(way->parent);
		way->parent->next = way;
		link = (*graph)[step->parent->id]->links;
		while (++i < (*graph)[step->parent->id]->count_links)
			if (link[i] == step->id)
				link[i] = -1;
		way = way->parent;
		if (way->id && way->id != g_count_room - 1 && !(*graph)[way->id]->occup)
			(*graph)[way->id]->occup = way;
		step = step->parent;
	}
	return (front);
}

static t_way		*new_way(t_room ***graph, t_way *list)
{
	t_way	*step;
	t_way	*way;

	way = NULL;
	list = create_lists_of_links(graph);
	step = list;
	while (step && step->id)
		step = step->next;
	if (step)
		way = create_way(step, graph);
	del_list(&list);
	return ((way && !way->id) ? way : NULL);
}

t_way				*dijkstra(t_room ***graph)
{
	t_way	*meta;
	t_way	*save;
	t_way	*path;

	meta = new_list(-1, NULL);
	path = meta;
	while (path)
	{
		path->next = new_list(-1, NULL);
		path = path->next;
		if (!(path->parent = new_way(graph, 0)))
			break ;
		meta->len += !!path->parent;
		untangle_ways(graph, &(path->parent));
		path->len = len_way(path->parent);
		if (!calc_efficiency(meta))
			break ;
		new_trash(save);
		save = copy_list(meta);
	}
	new_trash(meta);
	return (save);
}
