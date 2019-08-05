/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disjoint_path_finding.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 20:49:43 by solefir           #+#    #+#             */
/*   Updated: 2019/08/05 13:47:33 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static t_ways	*have_intersection(int *way, int size_way, t_ways *all)
{
	int		i;

	i = -1;
	while (all->next != NULL)
	{
		while (++i < size_way)
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
	while ((*a)->way[++i] <= (*a)->len_way)
		start_a = ft_memchr((const void*)(*b)->way, (*a)->way[++i], (size_t)(*b)->len_way);
	i = 0;
	while ((*b)->way[++i] <= (*b)->len_way)
		end_b = ft_memchr((const void*)(*a)->way, (*b)->way[i], (size_t)(*a)->len_way);
	if (f == 0)
		bhandari_disijoint(b, a, 1);
	temp = divorce(*a, *b, start_a, end_b);
	ft_masmemdel((void***)&(*a)->way, (size_t)(*a)->len_way);
	(*a)->way = temp;
	//(*a)->len_way = (*a)->len_way;
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
	print_ways(ways);
	temp = ways;
	/*while (temp->next != NULL)
	{
		if ((inter = have_intersection(temp->way, temp->len_way, ways)))
			bhandari_disijoint(&temp, &inter, 0);
		temp = temp->next;
	}
	ways = temp;*/
	return (ways);
}
