/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 15:52:16 by solefir           #+#    #+#             */
/*   Updated: 2019/08/06 17:00:18 by solefir          ###   ########.fr       */
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

t_way		*new_path(t_room ***graph)
{
	t_way	*list;
	t_way	*step;
	t_way	*front;
	t_way	*path;
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
	step = list;
	while (step && step->id)
		step = step->next;
	front = NULL;
	if (step)
	{
		path = new_list(step->id, NULL);
		(*graph)[path->id]->occup = path;
		front = path;
		while (step->parent)
		{
			path->next = new_list(step->parent->id, NULL);
			path->parent = path->next;
			i = 0;
			link = (*graph)[step->parent->id]->links;
			while (i < (*graph)[step->parent->id]->count_links)
			{
				if (link[i] == step->id)
					link[i] = -1;
				i++;
			}
			path = path->next;
			(*graph)[path->id]->occup = path;
			step = step->parent;
		}
	}
	//del list
	return ((front && !front->id) ? front : NULL);
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
		if (!(path->parent = new_path(graph)))
			break ;
		
		out_ways(meta);
	}
	return (meta);
}
