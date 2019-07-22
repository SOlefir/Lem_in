/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 12:40:04 by solefir           #+#    #+#             */
/*   Updated: 2019/07/22 20:48:27 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		g_count_ants = 0;
int		g_count_room = 0;
int		g_count_links = 0;

int		g_start = 0;
int		g_end = 0;

int		fd = 0;//
int		**g_arr_of_links = NULL;

int		main(void)
{
	int		error_nbr;
	t_list	*input;

	fd = open("../farm.txt", O_RDONLY);
	printf("FD: %d\n", fd);
	error_nbr = read_and_valid(&input);
	test(input);
	if (error_nbr >= 0)
		return (errors(error_nbr));
	//test(input);
	return (1);
}
