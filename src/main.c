/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 12:40:04 by solefir           #+#    #+#             */
/*   Updated: 2019/08/08 21:02:12 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		g_count_ants = 0;
int		g_count_room = 0;
int		g_count_links = 0;

int		new_trash(t_way *elem)
{
	t_way	*dup;

	dup = g_trash;
	while (dup->next)
		dup = dup->next;
	dup->next = new_list(-1, elem);
	return (1);
}

int		main(void)
{
	t_list		*input;
	t_room		**graph;
	t_way		*ways;
	t_way		**wsorted;
	int			*how_much;

	input = validation_and_write_in_lst();
	if (g_error_nbr >= 0)
		return (errors());
	graph = make_graph(input);
	g_trash = new_list(-1, NULL);
	ways = dijkstra(&graph);
	print_map(input);
	ft_printf("\n");
	wsorted = let_ants_go(ways, graph, &how_much);
	system("leaks lem-in");
	return (1);
}
