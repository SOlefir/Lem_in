/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 12:40:04 by solefir           #+#    #+#             */
/*   Updated: 2019/08/01 18:49:44 by solefir          ###   ########.fr       */
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
	//t_room		**graph;
	//t_ways		*ways;
	
	fd = open("../farm.txt", O_RDONLY);//
	printf("FD: %d\n", fd);//
	input = validation_and_write_in_lst();
	test(input);//
	if (g_error_nbr >= 0)
		return (errors());//дописать пояснение ошибок 6 - 8
	/*graph = make_graph(input);
	ways = disjoint_path_finding(&graph);
	//let_ants_go(ways, graph);*/
	return (1);
}

/* 
	добавить проверку на отсутствие ссылок/комнат и т.п.
	\/добавить проверку на эффективность дальнейшего поиска путей
	\/добавить контроль ситуации с  бутылочным горлышком
*/
