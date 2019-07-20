/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 12:40:04 by solefir           #+#    #+#             */
/*   Updated: 2019/07/20 20:10:00 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		main(void)
{
	int		error_nbr;
	t_list	*input;
	t_data	*farm;
	t_room	*rooms;
	t_ways	*all_ways;

	error_nbr = read_and_valid(input);
	if (error_nbr >= 0)
		return (errors(error_nbr));
	get_data(farm, input->farm);

	return (1);
}
