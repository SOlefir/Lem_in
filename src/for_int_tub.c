/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_int_tub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 19:58:25 by solefir           #+#    #+#             */
/*   Updated: 2019/07/31 20:15:35 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		revers(int *way)
{
	int	i;
	int	len;
	int	j;

	i = -1;
	len = count_len_way(way);
	while (--i != ++len)
	{
		j = way[i];
		way[i] = way[len];
		way[len] = j;
	}
}
