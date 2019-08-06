/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheack_way.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 14:05:14 by solefir           #+#    #+#             */
/*   Updated: 2019/08/05 13:44:43 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int			count_of_overlap_rooms(int *room1, int *room2)
{
	int	i;
	int	j;
	int	overl;

	i = 0;
	overl = 0;
	while (room1[i])
	{
		j = 0;
		while (room1[i + j] && room2[j])
		{
			if (room1[i + j] == room2[j])
				overl++;
			j++;
		}
		i++;
	}
	return (overl);
}

_Bool				is_bottle_neck(t_ways *ways, int *short_way)
{
	int		i;

	i = -1;
	while (ways != NULL)
	{
		if (count_of_overlap_rooms(ways->way, short_way) == 1)
			return (1);
		ways = ways->next;
	}
	return (0);
}

_Bool				is_effective_way(t_ways *ways, int steps_new_way)
{
	int	ants;
	int	all_steps;
	int	whith_new_way;
	int	count_ways;

	if (ways == NULL)
		return (1);
	count_ways = count_all_ways(ways);
	ants = (g_count_ants / count_ways) + (g_count_ants % count_ways);

	all_steps = count_all_steps(ways) / count_ways;
	all_steps += count_all_steps(ways) % count_ways;
	whith_new_way = (steps_new_way + all_steps) / (count_ways + 1);
	whith_new_way += (steps_new_way + all_steps) % (count_ways + 1);
	whith_new_way += (g_count_ants / count_ways) + (g_count_ants % count_ways);
	all_steps += (g_count_ants / count_ways + 1) +
												(g_count_ants % count_ways + 1);
	return (whith_new_way <= all_steps ? 1 : 0);
}
