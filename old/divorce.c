/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divorce.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: solefir <solefir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 20:16:25 by solefir           #+#    #+#             */
/*   Updated: 2019/08/01 21:53:01 by solefir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int			*divorce(t_ways *way_a, t_ways *way_b, int *start, int *end)
{
	int i;
	int	j;
	int	len;
	int	*new_way;

	j = -1;
	i = way_a->len_way + (way_b->len_way - (way_b->way - end));
	len = (way_b->len_way - (way_b->way - end)) + i;
	new_way = (int*)ft_memalloc(sizeof(int) * len);
	while (new_way[++j] != start[0])
		new_way[j] = way_a->way[j];
	i = -1;
	while (++j <= len)
		new_way[j] = end[++i];
	return (new_way);
}
