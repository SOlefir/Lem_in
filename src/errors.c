/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 20:20:29 by solefir           #+#    #+#             */
/*   Updated: 2019/07/22 13:07:32 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		errors(int	nbr_error)
{
	ft_putstr("ERROR: ");
	if (nbr_error == 0)
		ft_putstr("File is not completely filled or have empty line.");
	else if (nbr_error == 1)
	{
		ft_putstr("The number of start/end rooms is wrong.\n");
		ft_putstr("It must be one start and one end rooms - check it.");
	}
	else if (nbr_error == 2)
		ft_putstr("Not correct count of ants. Maybe you forgot about ants?");
	else if (nbr_error == 3)
		ft_putstr("Not valid rooms. Plees check room-names or coordinates.");
	else if (nbr_error == 4)
		ft_putstr("The links with rooms have incorrect write.");
	ft_putchar('\n');
	return (0);
}
