/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disjoint_path_finding.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 20:49:43 by solefir           #+#    #+#             */
/*   Updated: 2019/07/29 21:22:14 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int		have_intersection(t_ways **ways, int way)
{
	int	i;

	i = -1;
	while (ways[++i] && ways[way])
	{
		while (ways[i]->i )
	}
}

static void		bhandari_disijoint(t_ways **ways, int way_a, int way_b)
{

}

t_ways			**disjoint_path_finding(t_graph ***graph)
{
	t_ways	**ways;
	int		j;
	int		i;

	j = -1;
	i = 0;
	ways = dijkstra(&graph);
	while (ways[++j] != NULL)
		if (i = have_intersection(ways, j))
			bhandari_disijoint(&ways, j, i);
	return (ways);
}
