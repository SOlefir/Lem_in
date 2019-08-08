/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   let_ants_go.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 02:57:26 by solefir           #+#    #+#             */
/*   Updated: 2019/08/08 02:57:29 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void			put_zero_ants(t_way **ws)
{
	int		i;
	t_way	*way;

	i = -1;
	while ((way = ws[++i]))
	{
		while ((way = way->parent))
		{
			way->ant_inside = 0;
			way = way->parent;
		}
	}
}

t_way			**sort_ways(t_way *ways)
{
	t_way		**wsorted;
	t_way		*temp;
	int			i;
	int			j;
	int			size;

	wsorted = (t_way **)malloc(sizeof(t_way *) * (ways->len + 1));
	size = ways->len + 1;
	i = 0;
	while (ways)
	{
		wsorted[i++] = (ways->next) ? ways : ways->next;
		ways = ways->next;
	}
	i = -1;
	while (++i < size - 1)
	{
		j = size - 1;
		while (--j > i)
			if (wsorted[j]->len > wsorted[j - 1]->len)
			{
				temp = wsorted[j];
				wsorted[j] = wsorted[j - 1];
				wsorted[j - 1] = temp;
			}
	}
	wsorted[size] = NULL;
	return (wsorted);
}

int				*count_ways_ants(t_way **ws, int size)
{
	int		*data;
	int		ants;
	int		i;

	data = (int *)malloc(sizeof(int) * (size));
	i = -1;
	ants = g_count_ants;
	while (++i < size)
		data[i] = 0;
	while (ants--)
	{
		i = 0;
		while (i + 1 < size && 
			data[i] + ws[i]->len >= data[i + 1] + ws[i + 1]->len)
			i++;
		data[i]++;
	}
	return data;
}

void			let_ants_go(t_way *ways, t_room **graph)
{
	t_way		**wsorted;
	int			*how_much;
	int			ant_now;
	int			i;

	wsorted = sort_ways(ways);
	how_much = count_ways_ants(wsorted, ways->len);
	put_zero_ants(wsorted);
	ant_now = 0;
	while (ant_now != g_count_ants)
	{
		print_moves(wsorted, graph);
		make_moves(wsorted);
		i = -1;
		while (wsorted[++i])
			if (how_much[i] > 0 && how_much[i]--)
				add_ant_and_print(++ant_now, wsorted[i], graph);
		printf("\n");
	}
	print_moves(wsorted, graph);
	while (make_moves(wsorted) && printf("\n"))
		print_moves(wsorted, graph);
}
