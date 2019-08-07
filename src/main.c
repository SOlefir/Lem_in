/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 12:40:04 by solefir           #+#    #+#             */
/*   Updated: 2019/08/07 19:28:40 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		g_count_ants = 0;
int		g_count_room = 0;
int 	g_count_links = 0;

int		fd = 0;//

int		main(int ac, char **av)
{
	t_list		*input;
	t_room		**graph;
	t_way		*ways;

	if (ac != 2)
		return (0);
	fd = open(av[1], O_RDONLY);//
	printf("FD: %d\n", fd);//
	input = validation_and_write_in_lst();//дописать фнкцию на уникальность ссылки
	//test(input);//
	if (g_error_nbr >= 0)
		return (errors());//дописать пояснение ошибок 6 - 8
	graph = make_graph(input);
	//print_graph(graph);
	ways = dijkstra(&graph);
	//let_ants_go(ways, graph);
	//system("leaks lem-in");
	return (1);
}
