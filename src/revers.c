/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revers.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 19:58:25 by solefir           #+#    #+#             */
/*   Updated: 2019/08/01 17:24:46 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		reverse(int *way, int size)
{
	int	i;
	int	j;

	i = -1;
	while (--i != ++size)
	{
		j = way[i];
		way[i] = way[size];
		way[size] = j;
	}
}