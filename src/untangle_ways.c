/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   untangle_ways.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 12:58:35 by solefir           #+#    #+#             */
/*   Updated: 2019/08/07 19:03:46 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int			untangle_ways1(t_room **graph, t_way **way)
{
	t_way	*dupl;
	t_way	*(from[2]);
	t_way	*(to[2]);

	dupl = *way;
	while (dupl)
	{
		if (dupl->id && dupl->id != g_count_room - 1 &&
		graph[dupl->id]->occup != dupl && (to[0] = dupl))
		{
			from[0] = graph[dupl->id]->occup;
			while (from[0]->id == to[0]->id && (from[0] = from[0]->next))
				to[0] = to[0]->parent;
			from[1] = dupl;
			to[1] = graph[dupl->id]->occup;
			while (from[1]->id == to[1]->id && (to[1] = to[1]->parent))
				from[1] = from[1]->next;
			from[0]->parent->parent = to[0];
			to[0]->next = from[0]->parent;
			from[1]->parent->parent = to[1];
			to[1]->next = from[1]->parent;
			break ;
		}
		dupl = dupl->parent;
	}
	return ((dupl) ? untangle_ways2(graph, &(from[0])) : 1);
}

int			untangle_ways2(t_room **graph, t_way **way)
{
	t_way	*dupl;
	t_way	*(from[2]);
	t_way	*(to[2]);

	dupl = *way;
	while (dupl)
	{
		if (dupl->id && dupl->id != g_count_room - 1 &&
		graph[dupl->id]->occup != dupl && (to[0] = dupl))
		{
			from[0] = graph[dupl->id]->occup;
			while (from[0]->id == to[0]->id && (from[0] = from[0]->parent))
				to[0] = to[0]->next;
			from[1] = dupl;
			to[1] = graph[dupl->id]->occup;
			while (from[1]->id == to[1]->id && (to[1] = to[1]->next))
				from[1] = from[1]->parent;
			from[0]->next->next = to[0];
			to[0]->parent = from[0]->next;
			from[1]->next->next = to[1];
			to[1]->parent = from[1]->next;
			break ;
		}
		dupl = dupl->parent;
	}
	return ((dupl) ? untangle_ways1(graph, &(from[0])) : 1);
}
