/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 12:40:04 by solefir           #+#    #+#             */
/*   Updated: 2019/07/21 20:43:52 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		main(void)
{
	int		error_nbr;
	t_list	*input;

	error_nbr = read_and_valid(input);
	if (error_nbr >= 0)
		return (errors(error_nbr));
	test(input);
	return (1);
}
