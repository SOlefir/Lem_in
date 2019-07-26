/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 12:40:04 by solefir           #+#    #+#             */
/*   Updated: 2019/07/26 17:14:55 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		g_count_ants = 0;
int		g_count_room = 0;
int		g_count_links = 0;

int		g_count_ways = 1;
int		g_start_links = 0;
int		g_end_links = 0;

int		fd = 0;//

int		main(void)
{
	int			i;
	t_list		*input;
	t_graph		*graph;
	t_graph		**ways;
	t_struct_d	*data;
	
	i = 0;
	fd = open("farm.txt", O_RDONLY);//
	printf("FD: %d\n", fd);//
	input = validation_and_write_in_lst;
	test(input);
	data = g_error_nbr < 0 ? get_data(input) : NULL;
	if (g_error_nbr >= 0)
		return (errors);
	graph = make_graph(data);
	g_count_ways = (g_start_links <= g_end_links) ?
				g_start_links : g_end_links;
	ways = (t_graph**)malloc(sizeof(t_graph) * g_count_ways);
	while (i < g_count_ways && ways[i] != NULL)
	{
		ways[i] = dijkstra(graph);
		bhandari(graph, ways);
		i++;
	}
	let_ants_go(ways);
	//test(input);
	return (1);
}
/*
	пофиксить валидацию ссылок. 
	добавить проверку на отсутствие ссылок/комнат и т.п.
*/