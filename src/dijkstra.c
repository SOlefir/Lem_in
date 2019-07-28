/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 22:08:50 by solefir           #+#    #+#             */
/*   Updated: 2019/07/28 22:56:21 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		*find_short_way(t_graph **graph)
{

}

int		**dijkstra(t_graph ***graph)
{
	int	**ways;
	int	*short_way;
	int	count_ways;
	int	i;

	count_ways = possible_ways(*graph);
	ways = (int**)ft_memalloc(sizeof(int*) * count_ways);
	while ((short_way = find_short_way(*graph)) != NULL)
		ways[++i] = short_way;
	if (i != (count_ways - 1))
		cut_mass_arr(&ways, i);
	return (ways);
}