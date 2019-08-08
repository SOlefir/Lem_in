/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   let_ants_go.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 02:57:26 by solefir           #+#    #+#             */
/*   Updated: 2019/08/08 17:04:00 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_way			**sort_ways(t_way *ways)
{
	t_way		**wsorted;
	t_way		*temp;
	t_way		*lol;
	int			i;
	int			j;
	int			size;

	size = ways->len + 1;
	wsorted = (t_way **)malloc(sizeof(t_way *) * size);
	i = 0;
	ways = ways->next;
	while (ways)
	{
		lol = ways;
		wsorted[i++] = ways;
		ways = ways->next;
		lol->next = NULL;
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
		while (i < size - 1 && 
			data[i] + ws[i]->len >= data[i + 1] + ws[i + 1]->len)
			i++;
		data[i]++;
	}
	return (data);
}

void			let_ants_go(t_way *ways, t_room **graph)
{
	t_way		**wsorted;
	int			*how_much;
	int			ant_now;
	int			i;
	int			n;

	wsorted = sort_ways(ways);
	how_much = count_ways_ants(wsorted, ways->len);
	wsorted[ways->len] = NULL;
	ant_now = 0;
	n = 0;
	while (ant_now < g_count_ants)
	{
		print_moves(wsorted, graph);
		make_moves(wsorted);
		i = -1;
		while (wsorted[++i])
			if (how_much[i]--)
				add_ant_and_print(++ant_now, wsorted[i], graph);
		printf("\n");
		n++;
	}
	print_moves(wsorted, graph);
	while (make_moves(wsorted) && printf("\n"))
	{
		n++;
		print_moves(wsorted, graph);
	}
	printf("%d\n", n);
}
