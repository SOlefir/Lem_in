/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 12:40:04 by solefir           #+#    #+#             */
/*   Updated: 2019/07/29 21:26:08 by solefir          ###   ########.fr       */
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
	t_ways		**ways;
	
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
	пофиксить валидацию ссылок. и уточнить определение комнат/сылок и т.п.
	добавить проверку на отсутствие ссылок/комнат и т.п.
	добавить проверку на эффективность дальнейшего поиска путей
	добавить контроль ситуации с  бутылочным горлышком

	1. дописать бхандари; (2-3 часа)
	2. дописать для него функции поиска пересечений;
	3. проверить дейкстру; (2 часа)
	4. написать функцию вывода ходов муравьев;
	5. дописать валидацию;
	6. дописать сохранение данных;
	7. протестить и продебажить;

	вт. 
	1. дописать бхандари; (2-3 часа)
	2. дописать для него функции поиска пересечений;
	5. дописать валидацию;

	ср
	4. написать функцию вывода ходов муравьев;
	3. проверить дейкстру; (2 часа)
	6. дописать сохранение данных;
	7. протестить и продебажить;

*/