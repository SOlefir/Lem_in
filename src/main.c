/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 12:40:04 by solefir           #+#    #+#             */
/*   Updated: 2019/07/15 19:52:59 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		main(void)
{
	int		error_nbr;
	char	*data;
	t_data	*farm;
	t_room	*rooms;
	t_ways	*all_ways;

	data = NULL;
	error_nbr = 0;
	while (get_next_line(0, &data) > 0)
	{
		if ((error_nbr = validation(data)) > 0)
			return (errors(error_nbr));
		get_data(farm, data);
		ft_strdel(&data);
	}
	rooms = make_list_rooms(farm);
	make_global_arr_links(rooms, farm);
	all_ways = make_list_all_ways(farm);
	let_go_lemins(farm, all_ways);
	return (1);
}
