/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 12:40:04 by solefir           #+#    #+#             */
/*   Updated: 2019/07/31 17:37:11 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		g_count_ants = 0;
int		g_count_room = 0;
int		g_count_links = 0;

int		fd = 0;//

int		main(void)
{
	t_list		*input;
	t_room		**graph;
	t_ways		*ways;
	
	//i = 0;
	fd = open("../farm.txt", O_RDONLY);//
	printf("FD: %d\n", fd);//
	input = validation_and_write_in_lst();
	test(input);
	last_validation(input);
	if (g_error_nbr >= 0)
		return (errors());
	graph = make_graph(input);
	ways = disjoint_path_finding(&graph);
	let_ants_go(ways, graph);
	return (1);
}

/*
	пофиксить валидацию ссылок. 
	и уточнить определение комнат/сылок и т.п.
	добавить проверку на отсутствие ссылок/комнат и т.п.
	\/добавить проверку на эффективность дальнейшего поиска путей
	\/добавить контроль ситуации с  бутылочным горлышком

	. дописать валидацию;
	. написать функцию вывода ходов муравьев;
	. проверить дейкстру; (2 часа)
	. протестить и продебажить;

*/
