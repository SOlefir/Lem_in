/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 20:20:29 by solefir           #+#    #+#             */
/*   Updated: 2019/08/08 19:37:26 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		errors(void)
{
	ft_printf("ERROR: ");
	if (g_error_nbr == 0)
		ft_printf("File is not completely filled or have empty line.");
	else if (g_error_nbr == 1)
	{
		ft_printf("The number of start/end rooms is wrong.\n");
		ft_printf("It must be one start and one end rooms - check it.");
	}
	else if (g_error_nbr == 2)
		ft_printf("Not correct count of ants. Maybe you forgot about ants?");
	else if (g_error_nbr == 3)
		ft_printf("Not valid rooms. Plees check room-names or coordinates.");
	else if (g_error_nbr == 4)
		ft_printf("The links with rooms have incorrect write.");
	else if (g_error_nbr == 5)
		ft_printf("Not valid write");
	else if (g_error_nbr == 6)
		ft_printf("NO DATA\n");
	else if (g_error_nbr == 7)
		ft_printf("7\n");
	else if (g_error_nbr == 8)
		ft_printf("8\n");
	ft_putchar('\n');
	return (0);
}
