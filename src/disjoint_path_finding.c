/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disjoint_path_finding.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 20:49:43 by solefir           #+#    #+#             */
/*   Updated: 2019/07/31 20:44:05 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static t_ways	*have_intersection(int *way, t_ways *all)
{
	int		i;

	i = -1;
	while (all->next != NULL)
	{
		while (way[++i] != NULL)
			if (ft_memchr((const void*)all->way, way[i], (size_t)all->len_way))
				return (all);
		all = all->next;
	}
	return (all);
}

static void		bhandari_disijoint(t_ways **a, t_ways **b, int f)
{
	int	i;
	int	*end_b;
	int	*start_a;
	int	*temp;

	i = 0;
	start_a = NULL;
	end_b = NULL;
	while (start_a != NULL)
		start_a = ft_memchr((const void*)(*b)->way, (*a)->way[++i], (size_t)(*b)->len_way);
	i = 0;
	while ((*b)->way[++i] != NULL)
		end_b = ft_memchr((const void*)(*a)->way, (*b)->way[i], (size_t)(*a)->len_way);
	if (f = 0)
		bhandari_disijoint(b, a, 1);
	temp = divorce((*a)->way, start_a, end_b);
	ft_masmemdel((void***)&(*a)->way, (size_t)(*a)->len_way);
	(*a)->way = temp;
	(*a)->len_way = count_len_way((*a)->way);
}

t_ways			*disjoint_path_finding(t_room ***graph)
{
	t_ways	*ways;
	t_ways	*temp;
	t_ways	*inter;
	int		j;
	int		i;

	j = -1;
	i = 0;
	ways = dijkstra(graph);
	temp = ways;
	while (temp->next != NULL)
	{
		if (inter = have_intersection(temp->way, ways))
			bhandari_disijoint(&temp->way, &inter->way, 0);
		temp = temp->next;
	}
	return (ways);
}
