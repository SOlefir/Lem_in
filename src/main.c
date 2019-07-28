/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 12:40:04 by solefir           #+#    #+#             */
/*   Updated: 2019/07/28 23:00:42 by solefir          ###   ########.fr       */
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
	t_list		*input;
	t_graph		**graph;
	t_data		*data;
	int			**ways; //сделать листами
	
	//i = 0;
	fd = open("../farm.txt", O_RDONLY);//
	printf("FD: %d\n", fd);//
	input = validation_and_write_in_lst();
	test(input);
	last_validation(input);
	graph = make_graph(input);//создать массив ссылок на структуру с комнатами
	if (g_error_nbr >= 0)
		return (errors());
	ways = dijkstra(&graph);
	bhandari(&ways);
	let_ants_go(ways);
	return (1);
}
/*
	пофиксить валидацию ссылок. 
	добавить проверку на отсутствие ссылок/комнат и т.п.
*/